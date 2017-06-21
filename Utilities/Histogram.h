#ifndef Histogram_h
#define Histogram_h

// Header file for ROOT classes
#include <TH1.h>
#include <TLegend.h>
#include <TStyle.h>
#include <TSystem.h>
#include <TCanvas.h>

// Header file for c++ classes
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <iterator>

// CMS STYLE
#include "CMS/tdrstyle.C"
#include "CMS/CMS_lumi.C"


typedef struct VarInfo {
  std::string   label;
  unsigned int  nBin;
  float         min;
  float         max;
} VarInfo;

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
      *(result++) = item;
    }
}

std::vector<int> COLOR  = { kRed, kGreen+2, kBlue+2, kOrange+2, kViolet+2, kMagenta+2, kBlack };
std::vector<int> MARKER = { 22, 23, 24, 25, 26, 27, 28 };

class Histogram {

 public :

  Histogram();
  virtual ~Histogram();
  
  virtual void         Book    ( const std::string&, const std::map< std::string , struct VarInfo >& );
  virtual void         Fill    ( const std::string&, const std::map< std::string , float >& );
  virtual void         Draw    ( const std::string& );
  virtual void         Delete  ( void );

  std::map< std::string ,std::map< std::string , TH1F* > > TH1F_;

};

Histogram::Histogram()
{
  // set the CMS style
  setTDRStyle();
}
 
Histogram::~Histogram()
{
  Delete();
}

void 
Histogram::Book(const std::string& type, const std::map< std::string , struct VarInfo >& varMap)
{
  for (auto& var : varMap) {
    std::string    varName = var.first;
    struct VarInfo varInfo = var.second;
    std::string histName = (std::string("h_") + type + "_" + varName);
    if (TH1F_.count(type)==0 || TH1F_[type].count(varName)==0) {
      // Create the Histogram
      TH1F_[type][varName] = new TH1F(histName.c_str(), histName.c_str(), varInfo.nBin, varInfo.min, varInfo.max);
      // Initialize the Histogram
      TH1F_[type][varName]->GetYaxis()->SetTitle("Number of Entries");
      TH1F_[type][varName]->GetXaxis()->SetTitle(varInfo.label.c_str());
      std::cout << "[INFO] Added histogram: " << histName << std::endl;
    }
  }
}

void 
Histogram::Fill(const std::string& type, const std::map< std::string , float >& valueMap)
{
  for (auto& value : valueMap) {
    std::string varName  = value.first;
    if (TH1F_.count(type)>0 && TH1F_[type].count(varName)>0 && TH1F_[type][varName]) {
      TH1F_[type][varName]->Fill(value.second); 
    }
  }
}

void 
Histogram::Draw(const std::string& tag="")
{
  if (tag=="") return;
  // set the CMS style
  setTDRStyle();
  gSystem->mkdir("Plots", kTRUE);
  // Apply General Settings to all Histograms
  for (auto& t : TH1F_) {
    std::string type = t.first;
    for (auto& elem : TH1F_[type]) {
      std::string varName = elem.first;
      if (TH1F_[type][varName]) {
        //TH1F_[type][varName]->GetYaxis()->CenterTitle(kTRUE);
        TH1F_[type][varName]->GetYaxis()->SetTitleOffset(1.5);
        TH1F_[type][varName]->GetYaxis()->SetTitleSize(0.04);
        TH1F_[type][varName]->GetYaxis()->SetLabelSize(0.04);
        //TH1F_[type][varName]->GetXaxis()->CenterTitle(kTRUE);
        TH1F_[type][varName]->GetXaxis()->SetTitleOffset(1.0);
        TH1F_[type][varName]->GetXaxis()->SetTitleSize(0.048);
        TH1F_[type][varName]->GetXaxis()->SetLabelSize(0.04);
        TH1F_[type][varName]->SetMarkerColor(kBlack);
      }
    }
  }
  // Case: Separate -> Use one canvas for each histogram
  if (tag=="separate") {
    for (auto& t : TH1F_) {
      std::string type = t.first;
      for (auto& elem : TH1F_[type]) {
        std::string varName = elem.first;
        if (TH1F_[type][varName]) {
          std::string cName = (std::string("c_") + type + "_" + varName);
          TCanvas* c = new TCanvas(cName.c_str(), cName.c_str(), 1000, 1000);
          c->cd();
          TH1F_[type][varName]->Draw("p");
          c->Update();
          int option = 111;
          if (type.find("pPb")!=std::string::npos) option = 109;
          if (type.find("Pbp")!=std::string::npos) option = 110;
          CMS_lumi(c, option, 33, "");
          c->Update();
          c->SaveAs(Form("Plots/%s.png", cName.c_str()));
          c->Clear();
          c->Close();
          delete c;
        }
      }
    }
    return;
  }
  // Case: Together -> Draw all histograms in the same canvas
  // Case: Tagged -> Draw histograms with name containing Tag in the same canvas
  if (tag!="") {
    Double_t xl1=.20, yl1=0.75, xl2=xl1+.3, yl2=yl1+.125;
    std::string cName = ("c_"+tag); if (tag=="together") { cName = "c_JOIN"; }
    TCanvas* c = new TCanvas(cName.c_str(), cName.c_str(), 1000, 1000);
    TLegend *leg = new TLegend(xl1,yl1,xl2,yl2);
    bool firstDraw = true;
    uint i = 0;
    for (auto& t : TH1F_) {
      std::string type = t.first;
      for (auto& elem : TH1F_[type]) {
        std::string varName = elem.first;
        if ( TH1F_[type][varName] && (tag=="together" || type.find(tag)!=std::string::npos) ) {
          c->cd();
          TH1F_[type][varName]->SetMarkerColor(COLOR[i]);
          TH1F_[type][varName]->SetMarkerStyle(MARKER[i]);
          if (firstDraw) { TH1F_[type][varName]->Draw("P"); firstDraw = false; }
          else  TH1F_[type][varName]->Draw("SAMEP");
          std::string label = type + "_" + varName;
          if (tag!="together") { 
            if (label.find("_"+tag)!=std::string::npos) label.erase(label.find("_"+tag), ("_"+tag).size());
            else if (label.find(tag+"_")!=std::string::npos) label.erase(label.find(tag+"_"), (tag+"_").size());
            else if (label.find(tag)!=std::string::npos) label.erase(label.find(tag), tag.size());
          }
          leg->AddEntry(TH1F_[type][varName], label.c_str(), "p");
          i++;
        }
      }
    }
    leg->Draw("SAME");
    c->Update();
    int option = 111;
    if (tag.find("pPb")!=std::string::npos) option = 109;
    if (tag.find("Pbp")!=std::string::npos) option = 110;
    CMS_lumi(c, option, 33, "");
    c->Update();
    c->SaveAs(Form("Plots/%s.png", cName.c_str()));
    c->Clear();
    c->Close();
    delete c;
    return;
  }
}

void 
Histogram::Delete(void)
{
  for (auto& elem : TH1F_) { for (auto& hist : elem.second) { if (hist.second) delete hist.second; } }
}

#endif
