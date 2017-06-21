#ifndef HiConversionTree_h
#define HiConversionTree_h

// Header file for ROOT classes
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for c++ classes
#include <iostream>
#include <vector>
#include <map>

// Header file for the classes stored in the TTree
#include "TClonesArray.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TVector2.h"


typedef std::vector<TLorentzVector>           VTLorentzVector;
typedef std::vector<TVector3>                 VTVector3;
typedef std::vector< std::vector<UChar_t> >   UCharVecVec;
typedef std::vector< std::vector<UShort_t> >  UShortVecVec;

class HiConversionTree {

 public :

  HiConversionTree();
  virtual ~HiConversionTree();
  virtual Bool_t       GetTree    (const std::string&, TTree* tree = 0);
  virtual Int_t        GetEntry   (Long64_t);
  virtual Long64_t     GetEntries (void) { return fChain_->GetEntries(); }
  virtual TTree*       Tree       (void) { return fChain_; }
  virtual void         Clear      (void);

  // EVENT INFO VARIABLES
  UInt_t               Event_Run()                        { SetBranch("Event_Run");                        return Event_Run_;                             }
  UShort_t             Event_Lumi()                       { SetBranch("Event_Lumi");                       return Event_Lumi_;                            }
  UInt_t               Event_Bx()                         { SetBranch("Event_Bx");                         return Event_Bx_;                              }
  ULong64_t            Event_Orbit()                      { SetBranch("Event_Orbit");                      return Event_Orbit_;                           }
  ULong64_t            Event_Number()                     { SetBranch("Event_Number");                     return Event_Number_;                          }
  UChar_t              Event_nPV()                        { SetBranch("Event_nPV");                        return Event_nPV_;                             }
  TVector3             Event_PriVtx_Pos()                 { SetBranch("Event_PriVtx_Pos");                 return GET(Event_PriVtx_Pos_);                 }
  TVector3             Event_PriVtx_Err()                 { SetBranch("Event_PriVtx_Err");                 return GET(Event_PriVtx_Err_);                 }

  // RECO MUON VARIABLES
  VTLorentzVector         Reco_DiMuonConv_Mom()            { SetBranch("Reco_DiMuonConv_Mom");             return EXTRACTLV("Reco_DiMuonConv_Mom");       }
  std::vector<UShort_t>   Reco_DiMuonConv_Conversion_Idx() { SetBranch("Reco_DiMuonConv_Conversion_Idx");  return GET(Reco_DiMuonConv_Conversion_Idx_);   }
  std::vector<UShort_t>   Reco_DiMuonConv_DiMuon_Idx()     { SetBranch("Reco_DiMuonConv_DiMuon_Idx");      return GET(Reco_DiMuonConv_DiMuon_Idx_);       }
  std::vector<Float_t>    Reco_Chi_Mass()                  { SetBranch("Reco_Chi_Mass");                   return GET(Reco_Chi_Mass_);                    }
  std::vector<UChar_t>    Reco_Chi_Type()                  { SetBranch("Reco_Chi_Type");                   return GET(Reco_Chi_Type_);                    }

 private:

  virtual Long64_t     LoadTree        (Long64_t);
  virtual char         GetBranchStatus (const std::string&);
  virtual void         SetBranch       (const std::string&);
  virtual void         InitTree        (void);
  virtual Int_t        LoadEntry       (void) { return fChain_->GetEntry(entry_); }

  template <typename T> 
    T GET(T* x) { return ( (x) ? *x : T() ); }

  template <typename T, typename A> 
    void GETV(TClonesArray* c, std::vector<T,A>& v) { v.clear(); if (c) { for (int i=0; i < c->GetEntries(); i++) { v.push_back( *(dynamic_cast<T*>(c->At(i))) ); } } }

  VTLorentzVector EXTRACTLV(std::string name) { 
    if (GetBranchStatus(name)==1) {
      if (VTLorentzVector_[name].size()==0) { GETV(TClonesArray_[name], VTLorentzVector_[name]); } 
      return VTLorentzVector_[name]; 
    }
    return VTLorentzVector();
  }
  VTVector3 EXTRACTV3(std::string name) { 
    if (GetBranchStatus(name)==1) { 
      if (VTVector3_[name].size()==0) { GETV(TClonesArray_[name], VTVector3_[name]); } 
      return VTVector3_[name]; 
    }
    return VTVector3();
  }


  TTree*                    fChain_;
  std::map<string, TTree*>  fChainM_;
  Long64_t                  entry_;

  // TCLONEARRAY POINTERS
  std::map< std::string , TClonesArray*   > TClonesArray_;
  std::map< std::string , std::vector<TLorentzVector> > VTLorentzVector_;
  std::map< std::string , VTVector3       > VTVector3_;

  // EVENT INFO POINTERS
  UInt_t               Event_Run_    = 0;
  UShort_t             Event_Lumi_   = 0;
  UInt_t               Event_Bx_     = 0;
  ULong64_t            Event_Orbit_  = 0;
  ULong64_t            Event_Number_ = 0;
  UChar_t              Event_nPV_    = 0;
  TVector3             *Event_PriVtx_Pos_;
  TVector3             *Event_PriVtx_Err_;

  // RECO MUON POINTERS
  std::vector<UShort_t>  *Reco_DiMuonConv_Conversion_Idx_;
  std::vector<UShort_t>  *Reco_DiMuonConv_DiMuon_Idx_;
  std::vector<Float_t>   *Reco_Chi_Mass_;
  std::vector<UChar_t>   *Reco_Chi_Type_;

  // EVENT INFO BRANCHES
  TBranch        *b_Event_Run;   //!
  TBranch        *b_Event_Lumi;   //!
  TBranch        *b_Event_Bx;   //!
  TBranch        *b_Event_Orbit;   //!
  TBranch        *b_Event_Number;   //!
  TBranch        *b_Event_nPV;   //!
  TBranch        *b_Event_PriVtx_Pos;   //!
  TBranch        *b_Event_PriVtx_Err;   //!

  // RECO MUON BRANCHES
  TBranch        *b_Reco_DiMuonConv_Mom;   //!
  TBranch        *b_Reco_DiMuonConv_Conversion_Idx;   //!
  TBranch        *b_Reco_DiMuonConv_DiMuon_Idx;   //!
  TBranch        *b_Reco_Chi_Mass;   //!
  TBranch        *b_Reco_Chi_Type;   //!
};

HiConversionTree::HiConversionTree() : fChain_(0)
{
}

HiConversionTree::~HiConversionTree()
{
  if (fChain_ && fChain_->GetCurrentFile()) delete fChain_->GetCurrentFile();
}

Bool_t HiConversionTree::GetTree(const std::string& fileName, TTree* tree)
{
  // Open the input files
  TFile *f = TFile::Open(fileName.c_str());
  if (!f || !f->IsOpen()) return false;
  // Extract the input TTrees
  fChainM_.clear();
  TDirectory * dir;
  if (fileName.find("root://")!=std::string::npos) dir = (TDirectory*)f->Get("convAna");
  else dir = (TDirectory*)f->Get((fileName+":/convAna").c_str());
  if (!dir) return false;
  if (dir->GetListOfKeys()->Contains("Conversion_Event")) dir->GetObject("Conversion_Event",fChainM_["Event"]);
  if (dir->GetListOfKeys()->Contains("Conversion_Reco"))  dir->GetObject("Conversion_Reco", fChainM_["Reco"]);
  if (fChainM_.size()==0) return false;
  // Initialize the input TTrees (set their branches)
  InitTree();
  // Add Friend TTrees
  if (tree) { fChain_ = tree; }
  else      { fChain_ = fChainM_.begin()->second; }
  for (auto iter = fChainM_.begin(); iter != fChainM_.end(); iter++) {
    (iter->second)->SetMakeClass(1); // For the proper setup.
    if (iter->second != fChain_) {
      fChain_->AddFriend(iter->second); // Add the Friend TTree
      //(iter->second)->ResetBranchAddresses(); // Reset the branch address of the friend to avoid problems
    }
  }
  if (fChain_ == 0) return false;
  return true;
}

Int_t HiConversionTree::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  entry_ = entry;
  if (LoadTree(entry_) < 0) return -1;
  Clear();
  return LoadEntry();
}

Long64_t HiConversionTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain_) return -5;
   Long64_t centry = fChain_->LoadTree(entry);
   return centry;
}

char HiConversionTree::GetBranchStatus(const std::string& n)
{
  std::string type = n.substr(0, n.find("_"));
  if ( !(fChainM_.at(type)) || !(fChainM_.at(type)->GetBranch(n.c_str())) ) return -1;
  return fChainM_.at(type)->GetBranchStatus(n.c_str());
}

void HiConversionTree::SetBranch(const std::string& n)
{
  std::string type = n.substr(0, n.find("_"));
  if (GetBranchStatus(n) == 0) {
    fChainM_.at(type)->SetBranchStatus(n.c_str(), 1);
    LoadEntry(); // Needed for the first entry
  }
}

void HiConversionTree::InitTree(void)
{
  // INITIALIZE TCLONESARRAY
  TClonesArray_.clear();
  
  // INITIALIZE EVENT INFO POINTERS
  Event_PriVtx_Pos_ = 0;
  Event_PriVtx_Err_ = 0;

  // INITIALIZE RECO MUON POINTERS
  Reco_DiMuonConv_Conversion_Idx_ = 0;
  Reco_DiMuonConv_DiMuon_Idx_ = 0;
  Reco_Chi_Mass_ = 0;
  Reco_Chi_Type_ = 0;

  if (fChainM_.size()==0) return;

  // SET EVENT INFO BRANCHES
  if (fChainM_.count("Event")>0) {
    if (fChainM_["Event"]->GetBranch("Event_Run"))                       fChainM_["Event"]->SetBranchAddress("Event_Run", &Event_Run_, &b_Event_Run);
    if (fChainM_["Event"]->GetBranch("Event_Lumi"))                      fChainM_["Event"]->SetBranchAddress("Event_Lumi", &Event_Lumi_, &b_Event_Lumi);
    if (fChainM_["Event"]->GetBranch("Event_Bx"))                        fChainM_["Event"]->SetBranchAddress("Event_Bx", &Event_Bx_, &b_Event_Bx);
    if (fChainM_["Event"]->GetBranch("Event_Orbit"))                     fChainM_["Event"]->SetBranchAddress("Event_Orbit", &Event_Orbit_, &b_Event_Orbit);
    if (fChainM_["Event"]->GetBranch("Event_Number"))                    fChainM_["Event"]->SetBranchAddress("Event_Number", &Event_Number_, &b_Event_Number);
    if (fChainM_["Event"]->GetBranch("Event_nPV"))                       fChainM_["Event"]->SetBranchAddress("Event_nPV", &Event_nPV_, &b_Event_nPV);
    if (fChainM_["Event"]->GetBranch("Event_PriVtx_Pos"))                fChainM_["Event"]->SetBranchAddress("Event_PriVtx_Pos", &Event_PriVtx_Pos_, &b_Event_PriVtx_Pos);
    if (fChainM_["Event"]->GetBranch("Event_PriVtx_Err"))                fChainM_["Event"]->SetBranchAddress("Event_PriVtx_Err", &Event_PriVtx_Err_, &b_Event_PriVtx_Err);
    // Set All Branches to Status 0
    fChainM_["Event"]->SetBranchStatus("*",0);
  }

  // SET RECO MUON BRANCHES
  if (fChainM_.count("Reco")>0) {
    if (fChainM_["Reco"]->GetBranch("Reco_DiMuonConv_Mom"))              fChainM_["Reco"]->SetBranchAddress("Reco_DiMuonConv_Mom", &(TClonesArray_["Reco_DiMuonConv_Mom"]), &b_Reco_DiMuonConv_Mom);
    if (fChainM_["Reco"]->GetBranch("Reco_DiMuonConv_Conversion_Idx"))   fChainM_["Reco"]->SetBranchAddress("Reco_DiMuonConv_Conversion_Idx", &Reco_DiMuonConv_Conversion_Idx_, &b_Reco_DiMuonConv_Conversion_Idx);
    if (fChainM_["Reco"]->GetBranch("Reco_DiMuonConv_DiMuon_Idx"))       fChainM_["Reco"]->SetBranchAddress("Reco_DiMuonConv_DiMuon_Idx", &Reco_DiMuonConv_DiMuon_Idx_, &b_Reco_DiMuonConv_DiMuon_Idx);
    if (fChainM_["Reco"]->GetBranch("Reco_Chi_Mass"))                    fChainM_["Reco"]->SetBranchAddress("Reco_Chi_Mass", &Reco_Chi_Mass_, &b_Reco_Chi_Mass);
    if (fChainM_["Reco"]->GetBranch("Reco_Chi_Type"))                    fChainM_["Reco"]->SetBranchAddress("Reco_Chi_Type", &Reco_Chi_Type_, &b_Reco_Chi_Type);
    // Set All Branches to Status 0
    fChainM_["Reco"]->SetBranchStatus("*",0);
  }
}

void HiConversionTree::Clear(void)
{
  if (fChainM_.size()==0) return;

  // CLEAR TCLONESARRAY
  for(auto const &array : TClonesArray_) { if (array.second) { (array.second)->Clear(); } }
  VTLorentzVector_.clear();
  VTVector3_.clear();

  // CLEAR EVENT INFO VARIABLES
  Event_Run_    = 0;
  Event_Lumi_   = 0;
  Event_Bx_     = 0;
  Event_Orbit_  = 0;
  Event_Number_ = 0;
  Event_nPV_    = 0;
  if (Event_PriVtx_Pos_)                *Event_PriVtx_Pos_ = TVector3();
  if (Event_PriVtx_Err_)                *Event_PriVtx_Err_ = TVector3();
  
  // CLEAR RECO DIMUONCONV VARIABLES
  if (Reco_DiMuonConv_Conversion_Idx_)   Reco_DiMuonConv_Conversion_Idx_->clear();
  if (Reco_DiMuonConv_DiMuon_Idx_)       Reco_DiMuonConv_DiMuon_Idx_->clear();
  if (Reco_Chi_Mass_)                    Reco_Chi_Mass_->clear();
  if (Reco_Chi_Type_)                    Reco_Chi_Type_->clear();
}

#endif
