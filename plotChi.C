#include "Utilities/HiMuonTree.h"
#include "Utilities/HiConversionTree.h"
#include "Utilities/Histogram.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <iostream>

void plotChi()
{

  std::map< std::string , std::string > fileName = { 
    {"DATA"             , "/home/llr/cms/stahl/HIConversions/Test/CMSSW_8_0_26_patch2/src/crab_PARun2016C-v1_Run_DoubleMuon_285479_286504_CHIC_pA_20170503/results/HiChiForest.root"}
  };

  std::map< std::string , std::vector< std::string > > sampleType = {
    { "sample" , { "DATA" } },
    { "beam"   , { "PA" } }
  };

  std::map< std::string , struct VarInfo > varInfo = {
    { "ChiC_M"   , { "X_{C} Mass (GeV/c^{2})" , 100 , 3., 4. } },
    { "ChiB_M"   , { "X_{B} Mass (GeV/c^{2})" , 100 , 9., 12. } }
  };
  
  // Create the sample labels
  std::vector< std::string > samples;
  for (auto & sample : sampleType["sample"]) {
    if (sample=="DATA" && (fileName.count(sample)>0)) { samples.push_back(sample); }
    else {
      for (auto & beam : sampleType["beam"]) {
        std::string name = sample + "_" + beam;
        if ((fileName.count(name)>0)) { samples.push_back(name); }
      }
    }
  }

  // Extract all the samples        
  std::map< std::string , std::unique_ptr<HiMuonTree> > muonTree;
  std::map< std::string , std::unique_ptr<HiConversionTree> > convTree;
  std::map< std::string , Long64_t > nentries;
  for (auto & sample : samples) {
    muonTree[sample] = std::unique_ptr<HiMuonTree>(new HiMuonTree());
    if (!muonTree[sample]->GetTree(fileName[sample].c_str())) return;
    nentries[sample] = muonTree[sample]->GetEntries();
    convTree[sample] = std::unique_ptr<HiConversionTree>(new HiConversionTree());
    if (!convTree[sample]->GetTree(fileName[sample].c_str())) return;
    if (convTree[sample]->GetEntries() != nentries[sample]) { std::cout << "[ERROR] Inconsistent number of entries!" << std::endl; return; }
  }

  // Create the histogram labels
  Histogram hist = Histogram();
  std::vector< std::string > histName;
  for (auto & sample : sampleType["sample"]) {
    for (auto & beam : sampleType["beam"]) {
      std::string name = sample + "_" + beam;
      bool use = false;
      for (auto & s : samples) { if (name.find(s)!=std::string::npos) use = true; }
      if (use) histName.push_back(name);
    }
  }

  // Add the different histograms
  for (auto & type : histName) {
    hist.Book(type, varInfo);
  }

  uint nDiMuons = 0;
  uint nConv = 0;
  for (auto & sample : samples) {
    for (Long64_t jentry=0; jentry<nentries[sample]; jentry++) {
      if (muonTree[sample]->GetEntry(jentry)<0) break;
      if (convTree[sample]->GetEntry(jentry)<0) break;
      if (convTree[sample]->Event_Run() != muonTree[sample]->Event_Run()) { std::cout << "[ERROR] Inconsistent Run number!" << std::endl; return; }
      if (convTree[sample]->Event_Number() != muonTree[sample]->Event_Number()) { std::cout << "[ERROR] Inconsistent Event number!" << std::endl; return; }
      if (jentry%1000000==0) std::cout << sample << " : " << jentry << "/" << nentries[sample] << std::endl;

      std::map< std::string , float > valueMap;
      for (auto & name : histName) {
        if (name.find(sample)==std::string::npos) continue;
        bool keepEvent = true;
        if (keepEvent && ( name.find("DATA")!=std::string::npos && name.find("pPb")!=std::string::npos )) {
          if (!(muonTree[sample]->Event_Run() >= 285952 && muonTree[sample]->Event_Run() <= 286504)) keepEvent = false;
        }
        if (keepEvent && ( name.find("DATA")!=std::string::npos && name.find("Pbp")!=std::string::npos )) {
          if (!(muonTree[sample]->Event_Run() >= 285410 && muonTree[sample]->Event_Run() <= 285951)) keepEvent = false;
        }
        if (keepEvent && ( name.find("DATA")!=std::string::npos && name.find("PA")!=std::string::npos )) {
          keepEvent = true;
        }
        if (keepEvent) {
          std::map<double, bool> countDiMuon, countConv;
          for (uint i = 0; i < convTree[sample]->Reco_Chi_Type().size(); i++) {
            valueMap["ChiC_M"] = 0.;
            valueMap["ChiB_M"] = 0.;

            int iConv = convTree[sample]->Reco_DiMuonConv_Conversion_Idx().at(i);
            int iDM = convTree[sample]->Reco_DiMuonConv_DiMuon_Idx().at(i);
            bool found = true;
            float mass = convTree[sample]->Reco_Chi_Mass().at(i) + muonTree[sample]->Reco_DiMuon_Mom().at(iDM).M() - convTree[sample]->Reco_DiMuonConv_Mom().at(i).M();
            if (convTree[sample]->Reco_Chi_Type().at(i)==1) { 
              if ( abs(mass-3.096916) > 0.001 ) { return; }
            }
            if (convTree[sample]->Reco_Chi_Type().at(i)==2) { 
              if ( abs(mass-9.46030) > 0.001 ) { return; }
            }
            uint iM1 = muonTree[sample]->Reco_DiMuon_Muon1_Idx().at(iDM);
            uint iM2 = muonTree[sample]->Reco_DiMuon_Muon2_Idx().at(iDM);

            if ( 
                //(muonTree[sample]->Reco_Muon_isGlobal().at(iM1) || muonTree[sample]->Reco_Muon_isGlobal().at(iM2)) && // One of the two dimuons is Global
                (
                 (abs(muonTree[sample]->Reco_Muon_Mom().at(iM1).Eta()) < 1.6 &&  muonTree[sample]->Reco_Muon_Mom().at(iM1).Pt() > 3.0) ||
                 (abs(muonTree[sample]->Reco_Muon_Mom().at(iM1).Eta()) > 1.6 &&  muonTree[sample]->Reco_Muon_Mom().at(iM1).Pt() > 3.0)
                 ) &&
                (
                 (abs(muonTree[sample]->Reco_Muon_Mom().at(iM2).Eta()) < 1.6 &&  muonTree[sample]->Reco_Muon_Mom().at(iM2).Pt() > 3.0) ||
                 (abs(muonTree[sample]->Reco_Muon_Mom().at(iM2).Eta()) > 1.6 &&  muonTree[sample]->Reco_Muon_Mom().at(iM2).Pt() > 3.0)
                 )
                 )
              {
                if (convTree[sample]->Reco_Chi_Type().at(i)==1) { valueMap["ChiC_M"] = convTree[sample]->Reco_Chi_Mass().at(i); }
                if (convTree[sample]->Reco_Chi_Type().at(i)==2) { valueMap["ChiB_M"] = convTree[sample]->Reco_Chi_Mass().at(i); }
                float mass = convTree[sample]->Reco_Chi_Mass().at(i) + muonTree[sample]->Reco_DiMuon_Mom().at(iDM).M() - convTree[sample]->Reco_DiMuonConv_Mom().at(i).M();
                if (convTree[sample]->Reco_Chi_Type().at(i)==1) { 
                  if (countDiMuon.count(iDM)==0) { countDiMuon[iDM] = true; nDiMuons = nDiMuons + 1; }
                  if (countConv.count(iConv)==0) { countConv[iConv] = true; nConv = nConv + 1; }
                }
                hist.Fill(name, valueMap);
              }
          }
        }
      }
    }
  }

  cout << "Number of DiMuons: " << nDiMuons << " and number of conversions: " << nConv << endl;

  for (auto& sample : histName) { std::cout << sample << std::endl; }
  hist.Draw("separate");
}
