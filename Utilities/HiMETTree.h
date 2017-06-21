#ifndef HiMETTree_h
#define HiMETTree_h

// Header file for ROOT classes
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for c++ classes
#include <iostream>
#include <map>

// Header file for the classes stored in the TTree
#include "TVector2.h"
#include "TMatrixD.h"


class HiMETTree {

 public :

  HiMETTree();
  virtual ~HiMETTree();
  virtual Bool_t       GetTree    (const std::string&, TTree* tree = 0, const std::string& treeName="metAna");
  virtual Int_t        GetEntry   (Long64_t);
  virtual Long64_t     GetEntries (void) { return fChain_->GetEntries(); }
  virtual TTree*       Tree       (void) { return fChain_; }
  virtual void         Clear      (void);


  // EVENT INFO POINTERS
  UInt_t          Event_Run()                        { SetBranch("Event_Run");                        return Event_Run_;                             }
  UShort_t        Event_Lumi()                       { SetBranch("Event_Lumi");                       return Event_Lumi_;                            }
  UInt_t          Event_Bx()                         { SetBranch("Event_Bx");                         return Event_Bx_;                              }
  UInt_t          Event_Number()                     { SetBranch("Event_Number");                     return Event_Number_;                          }

  // RECO MET POINTERS
  TVector2        Reco_MET_Mom()                     { SetBranch("Reco_MET_Mom");                     return GET(Reco_MET_Mom_);                     }
  TMatrixD        Reco_MET_SigM()                    { SetBranch("Reco_MET_SigM");                    return GET(Reco_MET_SigM_);                    }
  Float_t         Reco_MET_Sig()                     { SetBranch("Reco_MET_Sig");                     return Reco_MET_Sig_;                          }
  Float_t         Reco_MET_sumEt()                   { SetBranch("Reco_MET_sumEt");                   return Reco_MET_sumEt_;                        }
  Float_t         Reco_MET_mEtSig()                  { SetBranch("Reco_MET_mEtSig");                  return Reco_MET_mEtSig_;                       }

  // PF MET POINTERS
  TVector2        PF_MET_Mom()                       { SetBranch("PF_MET_Mom");                       return GET(PF_MET_Mom_);                       }
  Float_t         PF_MET_Muon_Et()                   { SetBranch("PF_MET_Muon_Et");                   return PF_MET_Muon_Et_;                        }
  Float_t         PF_MET_Muon_EtFrac()               { SetBranch("PF_MET_Muon_EtFrac");               return PF_MET_Muon_EtFrac_;                    }
  Float_t         PF_MET_EM_Chg_Et()                 { SetBranch("PF_MET_EM_Chg_Et");                 return PF_MET_EM_Chg_Et_;                      }
  Float_t         PF_MET_EM_Chg_EtFrac()             { SetBranch("PF_MET_EM_Chg_EtFrac");             return PF_MET_EM_Chg_EtFrac_;                  }
  Float_t         PF_MET_EM_Neu_Et()                 { SetBranch("PF_MET_EM_Neu_Et");                 return PF_MET_EM_Neu_Et_;                      }
  Float_t         PF_MET_EM_Neu_EtFrac()             { SetBranch("PF_MET_EM_Neu_EtFrac");             return PF_MET_EM_Neu_EtFrac_;                  }
  Float_t         PF_MET_EM_HF_Et()                  { SetBranch("PF_MET_EM_HF_Et");                  return PF_MET_EM_HF_Et_;                       }
  Float_t         PF_MET_EM_HF_EtFrac()              { SetBranch("PF_MET_Had_Chg_Et");                return PF_MET_Had_Chg_Et_;                     }
  Float_t         PF_MET_Had_Chg_Et()                { SetBranch("PF_MET_Had_Chg_Et");                return PF_MET_Had_Chg_Et_;                     }
  Float_t         PF_MET_Had_Chg_EtFrac()            { SetBranch("PF_MET_Had_Chg_EtFrac");            return PF_MET_Had_Chg_EtFrac_;                 }
  Float_t         PF_MET_Had_Neu_Et()                { SetBranch("PF_MET_Had_Neu_Et");                return PF_MET_Had_Neu_Et_;                     }
  Float_t         PF_MET_Had_Neu_EtFrac()            { SetBranch("PF_MET_Had_Neu_EtFrac");            return PF_MET_Had_Neu_EtFrac_;                 }
  Float_t         PF_MET_Had_HF_Et()                 { SetBranch("PF_MET_Had_HF_Et");                 return PF_MET_Had_HF_Et_;                      }
  Float_t         PF_MET_Had_HF_EtFrac()             { SetBranch("PF_MET_Had_HF_EtFrac");             return PF_MET_Had_HF_EtFrac_;                  }
  TVector2        PF_MET_NoShift_Mom()               { SetBranch("PF_MET_NoShift_Mom");               return GET(PF_MET_NoShift_Mom_);               }
  Float_t         PF_MET_NoShift_sumEt()             { SetBranch("PF_MET_NoShift_sumEt");             return PF_MET_NoShift_sumEt_;                  }
  TVector2        PF_MET_ElectronEnDown_Mom()        { SetBranch("PF_MET_ElectronEnDown_Mom");        return GET(PF_MET_ElectronEnDown_Mom_);        }
  Float_t         PF_MET_ElectronEnDown_sumEt()      { SetBranch("PF_MET_ElectronEnDown_sumEt");      return PF_MET_ElectronEnDown_sumEt_;           }
  TVector2        PF_MET_ElectronEnUp_Mom()          { SetBranch("PF_MET_ElectronEnUp_Mom");          return GET(PF_MET_ElectronEnUp_Mom_);          }
  Float_t         PF_MET_ElectronEnUp_sumEt()        { SetBranch("PF_MET_ElectronEnUp_sumEt");        return PF_MET_ElectronEnUp_sumEt_;             }
  TVector2        PF_MET_JetEnDown_Mom()             { SetBranch("PF_MET_JetEnDown_Mom");             return GET(PF_MET_JetEnDown_Mom_);             }
  Float_t         PF_MET_JetEnDown_sumEt()           { SetBranch("PF_MET_JetEnDown_sumEt");           return PF_MET_JetEnDown_sumEt_;                }
  TVector2        PF_MET_JetEnUp_Mom()               { SetBranch("PF_MET_JetEnUp_Mom");               return GET(PF_MET_JetEnUp_Mom_);               }
  Float_t         PF_MET_JetEnUp_sumEt()             { SetBranch("PF_MET_JetEnUp_sumEt");             return PF_MET_JetEnUp_sumEt_;                  }
  TVector2        PF_MET_JetResDown_Mom()            { SetBranch("PF_MET_JetResDown_Mom");            return GET(PF_MET_JetResDown_Mom_);            }
  Float_t         PF_MET_JetResDown_sumEt()          { SetBranch("PF_MET_JetResDown_sumEt");          return PF_MET_JetResDown_sumEt_;               }
  TVector2        PF_MET_JetResUp_Mom()              { SetBranch("PF_MET_JetResUp_Mom");              return GET(PF_MET_JetResUp_Mom_);              }
  Float_t         PF_MET_JetResUp_sumEt()            { SetBranch("PF_MET_JetResUp_sumEt");            return PF_MET_JetResUp_sumEt_;                 }
  TVector2        PF_MET_MuonEnDown_Mom()            { SetBranch("PF_MET_MuonEnDown_Mom");            return GET(PF_MET_MuonEnDown_Mom_);            }
  Float_t         PF_MET_MuonEnDown_sumEt()          { SetBranch("PF_MET_MuonEnDown_sumEt");          return PF_MET_MuonEnDown_sumEt_;               }
  TVector2        PF_MET_MuonEnUp_Mom()              { SetBranch("PF_MET_MuonEnUp_Mom");              return GET(PF_MET_MuonEnUp_Mom_);              }
  Float_t         PF_MET_MuonEnUp_sumEt()            { SetBranch("PF_MET_MuonEnUp_sumEt");            return PF_MET_MuonEnUp_sumEt_;                 }
  TVector2        PF_MET_PhotonEnDown_Mom()          { SetBranch("PF_MET_PhotonEnDown_Mom");          return GET(PF_MET_PhotonEnDown_Mom_);          }
  Float_t         PF_MET_PhotonEnDown_sumEt()        { SetBranch("PF_MET_PhotonEnDown_sumEt");        return PF_MET_PhotonEnDown_sumEt_;             }
  TVector2        PF_MET_PhotonEnUp_Mom()            { SetBranch("PF_MET_PhotonEnUp_Mom");            return GET(PF_MET_PhotonEnUp_Mom_);            }
  Float_t         PF_MET_PhotonEnUp_sumEt()          { SetBranch("PF_MET_PhotonEnUp_sumEt");          return PF_MET_PhotonEnUp_sumEt_;               }
  TVector2        PF_MET_TauEnDown_Mom()             { SetBranch("PF_MET_TauEnDown_Mom");             return GET(PF_MET_TauEnDown_Mom_);             }
  Float_t         PF_MET_TauEnDown_sumEt()           { SetBranch("PF_MET_TauEnDown_sumEt");           return PF_MET_TauEnDown_sumEt_;                }
  TVector2        PF_MET_TauEnUp_Mom()               { SetBranch("PF_MET_TauEnUp_Mom");               return GET(PF_MET_TauEnUp_Mom_);               }
  Float_t         PF_MET_TauEnUp_sumEt()             { SetBranch("PF_MET_TauEnUp_sumEt");             return PF_MET_TauEnUp_sumEt_;                  }
  TVector2        PF_MET_UnclusEnDown_Mom()          { SetBranch("PF_MET_UnclusEnDown_Mom");          return GET(PF_MET_UnclusEnDown_Mom_);          }
  Float_t         PF_MET_UnclusEnDown_sumEt()        { SetBranch("PF_MET_UnclusEnDown_sumEt");        return PF_MET_UnclusEnDown_sumEt_;             }
  TVector2        PF_MET_UnclusEnUp_Mom()            { SetBranch("PF_MET_UnclusEnUp_Mom");            return GET(PF_MET_UnclusEnUp_Mom_);            }
  Float_t         PF_MET_UnclusEnUp_sumEt()          { SetBranch("PF_MET_UnclusEnUp_sumEt");          return PF_MET_UnclusEnUp_sumEt_;               }
  
  // CALO MET POINTERS
  TVector2        Calo_MET_Mom()                     { SetBranch("Calo_MET_Mom");                     return GET(Calo_MET_Mom_);                     }
  Float_t         Calo_MET_Sig()                     { SetBranch("Calo_MET_Sig");                     return Calo_MET_Sig_;                          }
  Float_t         Calo_MET_mHF_Et()                  { SetBranch("Calo_MET_mHF_Et");                  return Calo_MET_mHF_Et_;                       }
  Float_t         Calo_MET_mHF_Phi()                 { SetBranch("Calo_MET_mHF_Phi");                 return Calo_MET_mHF_Phi_;                      }
  Float_t         Calo_MET_mHF_sumEt()               { SetBranch("Calo_MET_mHF_sumEt");               return Calo_MET_mHF_sumEt_;                    }
  Float_t         Calo_MET_pHF_Et()                  { SetBranch("Calo_MET_pHF_Et");                  return Calo_MET_pHF_Et_;                       }
  Float_t         Calo_MET_pHF_Phi()                 { SetBranch("Calo_MET_pHF_Phi");                 return Calo_MET_pHF_Phi_;                      }
  Float_t         Calo_MET_pHF_sumEt()               { SetBranch("Calo_MET_pHF_sumEt");               return Calo_MET_pHF_sumEt_;                    }
  Float_t         Calo_MET_EM_EtFrac()               { SetBranch("Calo_MET_EM_EtFrac");               return Calo_MET_EM_EtFrac_;                    }
  Float_t         Calo_MET_EM_EB_Et()                { SetBranch("Calo_MET_EM_EB_Et");                return Calo_MET_EM_EB_Et_;                     }
  Float_t         Calo_MET_EM_EE_Et()                { SetBranch("Calo_MET_EM_EE_Et");                return Calo_MET_EM_EE_Et_;                     }
  Float_t         Calo_MET_EM_HF_Et()                { SetBranch("Calo_MET_EM_HF_Et");                return Calo_MET_EM_HF_Et_;                     }
  Float_t         Calo_MET_EM_Tow_maxEt()            { SetBranch("Calo_MET_EM_Tow_maxEt");            return Calo_MET_EM_Tow_maxEt_;                 }
  Float_t         Calo_MET_Had_EtFrac()              { SetBranch("Calo_MET_Had_EtFrac");              return Calo_MET_Had_EtFrac_;                   }
  Float_t         Calo_MET_Had_HB_Et()               { SetBranch("Calo_MET_Had_HB_Et");               return Calo_MET_Had_HB_Et_;                    }
  Float_t         Calo_MET_Had_HE_Et()               { SetBranch("Calo_MET_Had_HE_Et");               return Calo_MET_Had_HE_Et_;                    }
  Float_t         Calo_MET_Had_HF_Et()               { SetBranch("Calo_MET_Had_HF_Et");               return Calo_MET_Had_HF_Et_;                    }
  Float_t         Calo_MET_Had_HO_Et()               { SetBranch("Calo_MET_Had_HO_Et");               return Calo_MET_Had_HO_Et_;                    }
  Float_t         Calo_MET_Had_Tow_maxEt()           { SetBranch("Calo_MET_Had_Tow_maxEt");           return Calo_MET_Had_Tow_maxEt_;                }
  TVector2        Calo_MET_NoShift_Mom()             { SetBranch("Calo_MET_NoShift_Mom");             return GET(Calo_MET_NoShift_Mom_);             }
  Float_t         Calo_MET_NoShift_sumEt()           { SetBranch("Calo_MET_NoShift_sumEt");           return Calo_MET_NoShift_sumEt_;                }
  TVector2        Calo_MET_ElectronEnDown_Mom()      { SetBranch("Calo_MET_ElectronEnDown_Mom");      return GET(Calo_MET_ElectronEnDown_Mom_);      }
  Float_t         Calo_MET_ElectronEnDown_sumEt()    { SetBranch("Calo_MET_ElectronEnDown_sumEt");    return Calo_MET_ElectronEnDown_sumEt_;         }
  TVector2        Calo_MET_ElectronEnUp_Mom()        { SetBranch("Calo_MET_ElectronEnUp_Mom");        return GET(Calo_MET_ElectronEnUp_Mom_);        }
  Float_t         Calo_MET_ElectronEnUp_sumEt()      { SetBranch("Calo_MET_ElectronEnUp_sumEt");      return Calo_MET_ElectronEnUp_sumEt_;           }
  TVector2        Calo_MET_JetEnDown_Mom()           { SetBranch("Calo_MET_JetEnDown_Mom");           return GET(Calo_MET_JetEnDown_Mom_);           }
  Float_t         Calo_MET_JetEnDown_sumEt()         { SetBranch("Calo_MET_JetEnDown_sumEt");         return Calo_MET_JetEnDown_sumEt_;              }
  TVector2        Calo_MET_JetEnUp_Mom()             { SetBranch("Calo_MET_JetEnUp_Mom");             return GET(Calo_MET_JetEnUp_Mom_);             }
  Float_t         Calo_MET_JetEnUp_sumEt()           { SetBranch("Calo_MET_JetEnUp_sumEt");           return Calo_MET_JetEnUp_sumEt_;                }
  TVector2        Calo_MET_JetResDown_Mom()          { SetBranch("Calo_MET_JetResDown_Mom");          return GET(Calo_MET_JetResDown_Mom_);          }
  Float_t         Calo_MET_JetResDown_sumEt()        { SetBranch("Calo_MET_JetResDown_sumEt");        return Calo_MET_JetResDown_sumEt_;             }
  TVector2        Calo_MET_JetResUp_Mom()            { SetBranch("Calo_MET_JetResUp_Mom");            return GET(Calo_MET_JetResUp_Mom_);            }
  Float_t         Calo_MET_JetResUp_sumEt()          { SetBranch("Calo_MET_JetResUp_sumEt");          return Calo_MET_JetResUp_sumEt_;               }
  TVector2        Calo_MET_MuonEnDown_Mom()          { SetBranch("Calo_MET_MuonEnDown_Mom");          return GET(Calo_MET_MuonEnDown_Mom_);          }
  Float_t         Calo_MET_MuonEnDown_sumEt()        { SetBranch("Calo_MET_MuonEnDown_sumEt");        return Calo_MET_MuonEnDown_sumEt_;             }
  TVector2        Calo_MET_MuonEnUp_Mom()            { SetBranch("Calo_MET_MuonEnUp_Mom");            return GET(Calo_MET_MuonEnUp_Mom_);            }
  Float_t         Calo_MET_MuonEnUp_sumEt()          { SetBranch("Calo_MET_MuonEnUp_sumEt");          return Calo_MET_MuonEnUp_sumEt_;               }
  TVector2        Calo_MET_PhotonEnDown_Mom()        { SetBranch("Calo_MET_PhotonEnDown_Mom");        return GET(Calo_MET_PhotonEnDown_Mom_);        }
  Float_t         Calo_MET_PhotonEnDown_sumEt()      { SetBranch("Calo_MET_PhotonEnDown_sumEt");      return Calo_MET_PhotonEnDown_sumEt_;           }
  TVector2        Calo_MET_PhotonEnUp_Mom()          { SetBranch("Calo_MET_PhotonEnUp_Mom");          return GET(Calo_MET_PhotonEnUp_Mom_);          }
  Float_t         Calo_MET_PhotonEnUp_sumEt()        { SetBranch("Calo_MET_PhotonEnUp_sumEt");        return Calo_MET_PhotonEnUp_sumEt_;             }
  TVector2        Calo_MET_TauEnDown_Mom()           { SetBranch("Calo_MET_TauEnDown_Mom");           return GET(Calo_MET_TauEnDown_Mom_);           }
  Float_t         Calo_MET_TauEnDown_sumEt()         { SetBranch("Calo_MET_TauEnDown_sumEt");         return Calo_MET_TauEnDown_sumEt_;              }
  TVector2        Calo_MET_TauEnUp_Mom()             { SetBranch("Calo_MET_TauEnUp_Mom");             return GET(Calo_MET_TauEnUp_Mom_);             }
  Float_t         Calo_MET_TauEnUp_sumEt()           { SetBranch("Calo_MET_TauEnUp_sumEt");           return Calo_MET_TauEnUp_sumEt_;                }
  TVector2        Calo_MET_UnclusEnDown_Mom()        { SetBranch("Calo_MET_UnclusEnDown_Mom");        return GET(Calo_MET_UnclusEnDown_Mom_);        }
  Float_t         Calo_MET_UnclusEnDown_sumEt()      { SetBranch("Calo_MET_UnclusEnDown_sumEt");      return Calo_MET_UnclusEnDown_sumEt_;           }
  TVector2        Calo_MET_UnclusEnUp_Mom()          { SetBranch("Calo_MET_UnclusEnUp_Mom");          return GET(Calo_MET_UnclusEnUp_Mom_);          }
  Float_t         Calo_MET_UnclusEnUp_sumEt()        { SetBranch("Calo_MET_UnclusEnUp_sumEt");        return Calo_MET_UnclusEnUp_sumEt_;             }
                                                                                                                                                    
  // GEN MET POINTERS                                                                                                                               
  TVector2        Gen_MET_Mom()                      { SetBranch("Gen_MET_Mom");                      return GET(Gen_MET_Mom_);                      }
  Float_t         Gen_MET_Inv_Et()                   { SetBranch("Gen_MET_Inv_Et");                   return Gen_MET_Inv_Et_;                        }
  Float_t         Gen_MET_Inv_EtFrac()               { SetBranch("Gen_MET_Inv_EtFrac");               return Gen_MET_Inv_EtFrac_;                    }
  Float_t         Gen_MET_Muon_Et()                  { SetBranch("Gen_MET_Muon_Et");                  return Gen_MET_Muon_Et_;                       }
  Float_t         Gen_MET_Muon_EtFrac()              { SetBranch("Gen_MET_Muon_EtFrac");              return Gen_MET_Muon_EtFrac_;                   }
  Float_t         Gen_MET_EM_Chg_Et()                { SetBranch("Gen_MET_EM_Chg_Et");                return Gen_MET_EM_Chg_Et_;                     }
  Float_t         Gen_MET_EM_Chg_EtFrac()            { SetBranch("Gen_MET_EM_Chg_EtFrac");            return Gen_MET_EM_Chg_EtFrac_;                 }
  Float_t         Gen_MET_EM_Neu_Et()                { SetBranch("Gen_MET_EM_Neu_Et");                return Gen_MET_EM_Neu_Et_;                     }
  Float_t         Gen_MET_EM_Neu_EtFrac()            { SetBranch("Gen_MET_EM_Neu_EtFrac");            return Gen_MET_EM_Neu_EtFrac_;                 }
  Float_t         Gen_MET_Had_Chg_Et()               { SetBranch("Gen_MET_Had_Chg_Et");               return Gen_MET_Had_Chg_Et_;                    }
  Float_t         Gen_MET_Had_Chg_EtFrac()           { SetBranch("Gen_MET_Had_Chg_EtFrac");           return Gen_MET_Had_Chg_EtFrac_;                }
  Float_t         Gen_MET_Had_Neu_Et()               { SetBranch("Gen_MET_Had_Neu_Et");               return Gen_MET_Had_Neu_Et_;                    }
  Float_t         Gen_MET_Had_Neu_EtFrac()           { SetBranch("Gen_MET_Had_Neu_EtFrac");           return Gen_MET_Had_Neu_EtFrac_;                }

  // TYPE 1 CORRECTED MET POINTERS
  TVector2        Type1_MET_NoShift_Mom()            { SetBranch("Type1_MET_NoShift_Mom");           return GET(Type1_MET_NoShift_Mom_);             }
  Float_t         Type1_MET_NoShift_sumEt()          { SetBranch("Type1_MET_NoShift_sumEt");         return Type1_MET_NoShift_sumEt_;                }
  TVector2        Type1_MET_ElectronEnDown_Mom()     { SetBranch("Type1_MET_ElectronEnDown_Mom");    return GET(Type1_MET_ElectronEnDown_Mom_);      }
  Float_t         Type1_MET_ElectronEnDown_sumEt()   { SetBranch("Type1_MET_ElectronEnDown_sumEt");  return Type1_MET_ElectronEnDown_sumEt_;         }
  TVector2        Type1_MET_ElectronEnUp_Mom()       { SetBranch("Type1_MET_ElectronEnUp_Mom");      return GET(Type1_MET_ElectronEnUp_Mom_);        }
  Float_t         Type1_MET_ElectronEnUp_sumEt()     { SetBranch("Type1_MET_ElectronEnUp_sumEt");    return Type1_MET_ElectronEnUp_sumEt_;           }
  TVector2        Type1_MET_JetEnDown_Mom()          { SetBranch("Type1_MET_JetEnDown_Mom");         return GET(Type1_MET_JetEnDown_Mom_);           }
  Float_t         Type1_MET_JetEnDown_sumEt()        { SetBranch("Type1_MET_JetEnDown_sumEt");       return Type1_MET_JetEnDown_sumEt_;              }
  TVector2        Type1_MET_JetEnUp_Mom()            { SetBranch("Type1_MET_JetEnUp_Mom");           return GET(Type1_MET_JetEnUp_Mom_);             }
  Float_t         Type1_MET_JetEnUp_sumEt()          { SetBranch("Type1_MET_JetEnUp_sumEt");         return Type1_MET_JetEnUp_sumEt_;                }
  TVector2        Type1_MET_JetResDown_Mom()         { SetBranch("Type1_MET_JetResDown_Mom");        return GET(Type1_MET_JetResDown_Mom_);          }
  Float_t         Type1_MET_JetResDown_sumEt()       { SetBranch("Type1_MET_JetResDown_sumEt");      return Type1_MET_JetResDown_sumEt_;             }
  TVector2        Type1_MET_JetResUp_Mom()           { SetBranch("Type1_MET_JetResUp_Mom");          return GET(Type1_MET_JetResUp_Mom_);            }
  Float_t         Type1_MET_JetResUp_sumEt()         { SetBranch("Type1_MET_JetResUp_sumEt");        return Type1_MET_JetResUp_sumEt_;               }
  TVector2        Type1_MET_MuonEnDown_Mom()         { SetBranch("Type1_MET_MuonEnDown_Mom");        return GET(Type1_MET_MuonEnDown_Mom_);          }
  Float_t         Type1_MET_MuonEnDown_sumEt()       { SetBranch("Type1_MET_MuonEnDown_sumEt");      return Type1_MET_MuonEnDown_sumEt_;             }
  TVector2        Type1_MET_MuonEnUp_Mom()           { SetBranch("Type1_MET_MuonEnUp_Mom");          return GET(Type1_MET_MuonEnUp_Mom_);            }
  Float_t         Type1_MET_MuonEnUp_sumEt()         { SetBranch("Type1_MET_MuonEnUp_sumEt");        return Type1_MET_MuonEnUp_sumEt_;               }
  TVector2        Type1_MET_PhotonEnDown_Mom()       { SetBranch("Type1_MET_PhotonEnDown_Mom");      return GET(Type1_MET_PhotonEnDown_Mom_);        }
  Float_t         Type1_MET_PhotonEnDown_sumEt()     { SetBranch("Type1_MET_PhotonEnDown_sumEt");    return Type1_MET_PhotonEnDown_sumEt_;           }
  TVector2        Type1_MET_PhotonEnUp_Mom()         { SetBranch("Type1_MET_PhotonEnUp_Mom");        return GET(Type1_MET_PhotonEnUp_Mom_);          }
  Float_t         Type1_MET_PhotonEnUp_sumEt()       { SetBranch("Type1_MET_PhotonEnUp_sumEt");      return Type1_MET_PhotonEnUp_sumEt_;             }
  TVector2        Type1_MET_TauEnDown_Mom()          { SetBranch("Type1_MET_TauEnDown_Mom");         return GET(Type1_MET_TauEnDown_Mom_);           }
  Float_t         Type1_MET_TauEnDown_sumEt()        { SetBranch("Type1_MET_TauEnDown_sumEt");       return Type1_MET_TauEnDown_sumEt_;              }
  TVector2        Type1_MET_TauEnUp_Mom()            { SetBranch("Type1_MET_TauEnUp_Mom");           return GET(Type1_MET_TauEnUp_Mom_);             }
  Float_t         Type1_MET_TauEnUp_sumEt()          { SetBranch("Type1_MET_TauEnUp_sumEt");         return Type1_MET_TauEnUp_sumEt_;                }
  TVector2        Type1_MET_UnclusEnDown_Mom()       { SetBranch("Type1_MET_UnclusEnDown_Mom");      return GET(Type1_MET_UnclusEnDown_Mom_);        }
  Float_t         Type1_MET_UnclusEnDown_sumEt()     { SetBranch("Type1_MET_UnclusEnDown_sumEt");    return Type1_MET_UnclusEnDown_sumEt_;           }
  TVector2        Type1_MET_UnclusEnUp_Mom()         { SetBranch("Type1_MET_UnclusEnUp_Mom");        return GET(Type1_MET_UnclusEnUp_Mom_);          }
  Float_t         Type1_MET_UnclusEnUp_sumEt()       { SetBranch("Type1_MET_UnclusEnUp_sumEt");      return Type1_MET_UnclusEnUp_sumEt_;             }

  // TYPE XY CORRECTED MET POINTERS
  TVector2        TypeXY_MET_NoShift_Mom()           { SetBranch("TypeXY_MET_NoShift_Mom");          return GET(TypeXY_MET_NoShift_Mom_);            }
  Float_t         TypeXY_MET_NoShift_sumEt()         { SetBranch("TypeXY_MET_NoShift_sumEt");        return TypeXY_MET_NoShift_sumEt_;               }
  TVector2        TypeXY_MET_ElectronEnDown_Mom()    { SetBranch("TypeXY_MET_ElectronEnDown_Mom");   return GET(TypeXY_MET_ElectronEnDown_Mom_);     }
  Float_t         TypeXY_MET_ElectronEnDown_sumEt()  { SetBranch("TypeXY_MET_ElectronEnDown_sumEt"); return TypeXY_MET_ElectronEnDown_sumEt_;        }
  TVector2        TypeXY_MET_ElectronEnUp_Mom()      { SetBranch("TypeXY_MET_ElectronEnUp_Mom");     return GET(TypeXY_MET_ElectronEnUp_Mom_);       }
  Float_t         TypeXY_MET_ElectronEnUp_sumEt()    { SetBranch("TypeXY_MET_ElectronEnUp_sumEt");   return TypeXY_MET_ElectronEnUp_sumEt_;          }
  TVector2        TypeXY_MET_JetEnDown_Mom()         { SetBranch("TypeXY_MET_JetEnDown_Mom");        return GET(TypeXY_MET_JetEnDown_Mom_);          }
  Float_t         TypeXY_MET_JetEnDown_sumEt()       { SetBranch("TypeXY_MET_JetEnDown_sumEt");      return TypeXY_MET_JetEnDown_sumEt_;             }
  TVector2        TypeXY_MET_JetEnUp_Mom()           { SetBranch("TypeXY_MET_JetEnUp_Mom");          return GET(TypeXY_MET_JetEnUp_Mom_);            }
  Float_t         TypeXY_MET_JetEnUp_sumEt()         { SetBranch("TypeXY_MET_JetEnUp_sumEt");        return TypeXY_MET_JetEnUp_sumEt_;               }
  TVector2        TypeXY_MET_JetResDown_Mom()        { SetBranch("TypeXY_MET_JetResDown_Mom");       return GET(TypeXY_MET_JetResDown_Mom_);         }
  Float_t         TypeXY_MET_JetResDown_sumEt()      { SetBranch("TypeXY_MET_JetResDown_sumEt");     return TypeXY_MET_JetResDown_sumEt_;            }
  TVector2        TypeXY_MET_JetResUp_Mom()          { SetBranch("TypeXY_MET_JetResUp_Mom");         return GET(TypeXY_MET_JetResUp_Mom_);           }
  Float_t         TypeXY_MET_JetResUp_sumEt()        { SetBranch("TypeXY_MET_JetResUp_sumEt");       return TypeXY_MET_JetResUp_sumEt_;              }
  TVector2        TypeXY_MET_MuonEnDown_Mom()        { SetBranch("TypeXY_MET_MuonEnDown_Mom");       return GET(TypeXY_MET_MuonEnDown_Mom_);         }
  Float_t         TypeXY_MET_MuonEnDown_sumEt()      { SetBranch("TypeXY_MET_MuonEnDown_sumEt");     return TypeXY_MET_MuonEnDown_sumEt_;            }
  TVector2        TypeXY_MET_MuonEnUp_Mom()          { SetBranch("TypeXY_MET_MuonEnUp_Mom");         return GET(TypeXY_MET_MuonEnUp_Mom_);           }
  Float_t         TypeXY_MET_MuonEnUp_sumEt()        { SetBranch("TypeXY_MET_MuonEnUp_sumEt");       return TypeXY_MET_MuonEnUp_sumEt_;              }
  TVector2        TypeXY_MET_PhotonEnDown_Mom()      { SetBranch("TypeXY_MET_PhotonEnDown_Mom");     return GET(TypeXY_MET_PhotonEnDown_Mom_);       }
  Float_t         TypeXY_MET_PhotonEnDown_sumEt()    { SetBranch("TypeXY_MET_PhotonEnDown_sumEt");   return TypeXY_MET_PhotonEnDown_sumEt_;          }
  TVector2        TypeXY_MET_PhotonEnUp_Mom()        { SetBranch("TypeXY_MET_PhotonEnUp_Mom");       return GET(TypeXY_MET_PhotonEnUp_Mom_);         }
  Float_t         TypeXY_MET_PhotonEnUp_sumEt()      { SetBranch("TypeXY_MET_PhotonEnUp_sumEt");     return TypeXY_MET_PhotonEnUp_sumEt_;            }
  TVector2        TypeXY_MET_TauEnDown_Mom()         { SetBranch("TypeXY_MET_TauEnDown_Mom");        return GET(TypeXY_MET_TauEnDown_Mom_);          }
  Float_t         TypeXY_MET_TauEnDown_sumEt()       { SetBranch("TypeXY_MET_TauEnDown_sumEt");      return TypeXY_MET_TauEnDown_sumEt_;             }
  TVector2        TypeXY_MET_TauEnUp_Mom()           { SetBranch("TypeXY_MET_TauEnUp_Mom");          return GET(TypeXY_MET_TauEnUp_Mom_);            }
  Float_t         TypeXY_MET_TauEnUp_sumEt()         { SetBranch("TypeXY_MET_TauEnUp_sumEt");        return TypeXY_MET_TauEnUp_sumEt_;               }
  TVector2        TypeXY_MET_UnclusEnDown_Mom()      { SetBranch("TypeXY_MET_UnclusEnDown_Mom");     return GET(TypeXY_MET_UnclusEnDown_Mom_);       }
  Float_t         TypeXY_MET_UnclusEnDown_sumEt()    { SetBranch("TypeXY_MET_UnclusEnDown_sumEt");   return TypeXY_MET_UnclusEnDown_sumEt_;          }
  TVector2        TypeXY_MET_UnclusEnUp_Mom()        { SetBranch("TypeXY_MET_UnclusEnUp_Mom");       return GET(TypeXY_MET_UnclusEnUp_Mom_);         }
  Float_t         TypeXY_MET_UnclusEnUp_sumEt()      { SetBranch("TypeXY_MET_UnclusEnUp_sumEt");     return TypeXY_MET_UnclusEnUp_sumEt_;            }

  // MET FILTER POINTERS
  Bool_t          Flag_BadChargedCandidateFilter()          { SetBranch("Flag_BadChargedCandidateFilter");          return Flag_BadChargedCandidateFilter_;           }
  Bool_t          Flag_BadChargedCandidateSummer16Filter()  { SetBranch("Flag_BadChargedCandidateSummer16Filter");  return Flag_BadChargedCandidateSummer16Filter_;   }
  Bool_t          Flag_BadPFMuonFilter()                    { SetBranch("Flag_BadPFMuonFilter");                    return Flag_BadPFMuonFilter_;                     }
  Bool_t          Flag_BadPFMuonSummer16Filter()            { SetBranch("Flag_BadPFMuonSummer16Filter");            return Flag_BadPFMuonSummer16Filter_;             }
  Bool_t          Flag_CSCTightHalo2015Filter()             { SetBranch("Flag_CSCTightHalo2015Filter");             return Flag_CSCTightHalo2015Filter_;              }
  Bool_t          Flag_CSCTightHaloFilter()                 { SetBranch("Flag_CSCTightHaloFilter");                 return Flag_CSCTightHaloFilter_;                  }
  Bool_t          Flag_CSCTightHaloTrkMuUnvetoFilter()      { SetBranch("Flag_CSCTightHaloTrkMuUnvetoFilter");      return Flag_CSCTightHaloTrkMuUnvetoFilter_;       }
  Bool_t          Flag_EcalDeadCellBoundaryEnergyFilter()   { SetBranch("Flag_EcalDeadCellBoundaryEnergyFilter");   return Flag_EcalDeadCellBoundaryEnergyFilter_;    }
  Bool_t          Flag_EcalDeadCellTriggerPrimitiveFilter() { SetBranch("Flag_EcalDeadCellTriggerPrimitiveFilter"); return Flag_EcalDeadCellTriggerPrimitiveFilter_;  }
  Bool_t          Flag_HBHENoiseFilter()                    { SetBranch("Flag_HBHENoiseFilter");                    return Flag_HBHENoiseFilter_;                     }
  Bool_t          Flag_HBHENoiseFilterRun1()                { SetBranch("Flag_HBHENoiseFilterRun1");                return Flag_HBHENoiseFilterRun1_;                 }
  Bool_t          Flag_HBHENoiseFilterRun2Loose()           { SetBranch("Flag_HBHENoiseFilterRun2Loose");           return Flag_HBHENoiseFilterRun2Loose_;            }
  Bool_t          Flag_HBHENoiseFilterRun2Tight()           { SetBranch("Flag_HBHENoiseFilterRun2Tight");           return Flag_HBHENoiseFilterRun2Tight_;            }
  Bool_t          Flag_HBHENoiseIsoFilter()                 { SetBranch("Flag_HBHENoiseIsoFilter");                 return Flag_HBHENoiseIsoFilter_;                  }
  Bool_t          Flag_HcalStripHaloFilter()                { SetBranch("Flag_HcalStripHaloFilter");                return Flag_HcalStripHaloFilter_;                 }
  Bool_t          Flag_badMuons()                           { SetBranch("Flag_badMuons");                           return Flag_badMuons_;                            }
  Bool_t          Flag_badTrackerMuons()                    { SetBranch("Flag_badTrackerMuons");                    return Flag_badTrackerMuons_;                     }
  Bool_t          Flag_chargedHadronTrackResolutionFilter() { SetBranch("Flag_chargedHadronTrackResolutionFilter"); return Flag_chargedHadronTrackResolutionFilter_;  }
  Bool_t          Flag_collisionEventSelectionPA()          { SetBranch("Flag_collisionEventSelectionPA");          return Flag_collisionEventSelectionPA_;           }
  Bool_t          Flag_collisionEventSelectionPA_rejectPU() { SetBranch("Flag_collisionEventSelectionPA_rejectPU"); return Flag_collisionEventSelectionPA_rejectPU_;  }
  Bool_t          Flag_duplicateMuons()                     { SetBranch("Flag_duplicateMuons");                     return Flag_duplicateMuons_;                      }
  Bool_t          Flag_ecalLaserCorrFilter()                { SetBranch("Flag_ecalLaserCorrFilter");                return Flag_ecalLaserCorrFilter_;                 }
  Bool_t          Flag_eeBadScFilter()                      { SetBranch("Flag_eeBadScFilter");                      return Flag_eeBadScFilter_;                       }
  Bool_t          Flag_globalSuperTightHalo2016Filter()     { SetBranch("Flag_globalSuperTightHalo2016Filter");     return Flag_globalSuperTightHalo2016Filter_;      }
  Bool_t          Flag_globalTightHalo2016Filter()          { SetBranch("Flag_globalTightHalo2016Filter");          return Flag_globalTightHalo2016Filter_;           }
  Bool_t          Flag_goodVertices()                       { SetBranch("Flag_goodVertices");                       return Flag_goodVertices_;                        }
  Bool_t          Flag_hcalLaserEventFilter()               { SetBranch("Flag_hcalLaserEventFilter");               return Flag_hcalLaserEventFilter_;                }
  Bool_t          Flag_muonBadTrackFilter()                 { SetBranch("Flag_muonBadTrackFilter");                 return Flag_muonBadTrackFilter_;                  }
  Bool_t          Flag_noBadMuons()                         { SetBranch("Flag_noBadMuons");                         return Flag_noBadMuons_;                          }
  Bool_t          Flag_trkPOGFilters()                      { SetBranch("Flag_trkPOGFilters");                      return Flag_trkPOGFilters_;                       }
  Bool_t          Flag_trkPOG_logErrorTooManyClusters()     { SetBranch("Flag_trkPOG_logErrorTooManyClusters");     return Flag_trkPOG_logErrorTooManyClusters_;      }
  Bool_t          Flag_trkPOG_manystripclus53X()            { SetBranch("Flag_trkPOG_manystripclus53X");            return Flag_trkPOG_manystripclus53X_;             }
  Bool_t          Flag_trkPOG_toomanystripclus53X()         { SetBranch("Flag_trkPOG_toomanystripclus53X");         return Flag_trkPOG_toomanystripclus53X_;          }

  //private:

  virtual Long64_t     LoadTree   (Long64_t);
  virtual void         SetBranch  (const std::string&);
  virtual void         InitTree   (void);
  virtual Int_t        LoadEntry  (void) { return fChain_->GetEntry(entry_); }

  template <typename T>
    T GET(T* x) { return ( (x) ? *x : T() ); }

  TTree*                    fChain_;
  std::map<string, TTree*>  fChainM_;
  Long64_t                  entry_;
  
  // EVENT INFO POINTERS
  UInt_t          Event_Run_    = 0;
  UShort_t        Event_Lumi_   = 0;
  UInt_t          Event_Bx_     = 0;
  UInt_t          Event_Number_ = 0;

  // RECO MET POINTERS
  TVector2        *Reco_MET_Mom_;
  TMatrixD        *Reco_MET_SigM_;
  Float_t         Reco_MET_Sig_    = -1.;
  Float_t         Reco_MET_sumEt_  = -1.;
  Float_t         Reco_MET_mEtSig_ = -1.;

  // PF MET POINTERS
  TVector2        *PF_MET_Mom_;
  Float_t         PF_MET_Muon_Et_ = -1.;
  Float_t         PF_MET_Muon_EtFrac_ = -1.;
  Float_t         PF_MET_EM_Chg_Et_ = -1.;
  Float_t         PF_MET_EM_Chg_EtFrac_ = -1.;
  Float_t         PF_MET_EM_Neu_Et_ = -1.;
  Float_t         PF_MET_EM_Neu_EtFrac_ = -1.;
  Float_t         PF_MET_EM_HF_Et_ = -1.;
  Float_t         PF_MET_EM_HF_EtFrac_ = -1.;
  Float_t         PF_MET_Had_Chg_Et_ = -1.;
  Float_t         PF_MET_Had_Chg_EtFrac_ = -1.;
  Float_t         PF_MET_Had_Neu_Et_ = -1.;
  Float_t         PF_MET_Had_Neu_EtFrac_ = -1.;
  Float_t         PF_MET_Had_HF_Et_ = -1.;
  Float_t         PF_MET_Had_HF_EtFrac_ = -1.;
  TVector2        *PF_MET_NoShift_Mom_;
  Float_t         PF_MET_NoShift_sumEt_ = -1.;
  TVector2        *PF_MET_ElectronEnDown_Mom_;
  Float_t         PF_MET_ElectronEnDown_sumEt_ = -1.;
  TVector2        *PF_MET_ElectronEnUp_Mom_;
  Float_t         PF_MET_ElectronEnUp_sumEt_ = -1.;
  TVector2        *PF_MET_JetEnDown_Mom_;
  Float_t         PF_MET_JetEnDown_sumEt_ = -1.;
  TVector2        *PF_MET_JetEnUp_Mom_;
  Float_t         PF_MET_JetEnUp_sumEt_ = -1.;
  TVector2        *PF_MET_JetResDown_Mom_;
  Float_t         PF_MET_JetResDown_sumEt_ = -1.;
  TVector2        *PF_MET_JetResUp_Mom_;
  Float_t         PF_MET_JetResUp_sumEt_ = -1.;
  TVector2        *PF_MET_MuonEnDown_Mom_;
  Float_t         PF_MET_MuonEnDown_sumEt_ = -1.;
  TVector2        *PF_MET_MuonEnUp_Mom_;
  Float_t         PF_MET_MuonEnUp_sumEt_ = -1.;
  TVector2        *PF_MET_PhotonEnDown_Mom_;
  Float_t         PF_MET_PhotonEnDown_sumEt_ = -1.;
  TVector2        *PF_MET_PhotonEnUp_Mom_;
  Float_t         PF_MET_PhotonEnUp_sumEt_ = -1.;
  TVector2        *PF_MET_TauEnDown_Mom_;
  Float_t         PF_MET_TauEnDown_sumEt_ = -1.;
  TVector2        *PF_MET_TauEnUp_Mom_;
  Float_t         PF_MET_TauEnUp_sumEt_ = -1.;
  TVector2        *PF_MET_UnclusEnDown_Mom_;
  Float_t         PF_MET_UnclusEnDown_sumEt_ = -1.;
  TVector2        *PF_MET_UnclusEnUp_Mom_;
  Float_t         PF_MET_UnclusEnUp_sumEt_ = -1.;
  
  // CALO MET POINTERS
  TVector2        *Calo_MET_Mom_;
  Float_t         Calo_MET_Sig_ = -1.;
  Float_t         Calo_MET_mHF_Et_ = -1.;
  Float_t         Calo_MET_mHF_Phi_ = -1.;
  Float_t         Calo_MET_mHF_sumEt_ = -1.;
  Float_t         Calo_MET_pHF_Et_ = -1.;
  Float_t         Calo_MET_pHF_Phi_ = -1.;
  Float_t         Calo_MET_pHF_sumEt_ = -1.;
  Float_t         Calo_MET_EM_EtFrac_ = -1.;
  Float_t         Calo_MET_EM_EB_Et_ = -1.;
  Float_t         Calo_MET_EM_EE_Et_ = -1.;
  Float_t         Calo_MET_EM_HF_Et_ = -1.;
  Float_t         Calo_MET_EM_Tow_maxEt_ = -1.;
  Float_t         Calo_MET_Had_EtFrac_ = -1.;
  Float_t         Calo_MET_Had_HB_Et_ = -1.;
  Float_t         Calo_MET_Had_HE_Et_ = -1.;
  Float_t         Calo_MET_Had_HF_Et_ = -1.;
  Float_t         Calo_MET_Had_HO_Et_ = -1.;
  Float_t         Calo_MET_Had_Tow_maxEt_ = -1.;
  TVector2        *Calo_MET_NoShift_Mom_;
  Float_t         Calo_MET_NoShift_sumEt_ = -1.;
  TVector2        *Calo_MET_ElectronEnDown_Mom_;
  Float_t         Calo_MET_ElectronEnDown_sumEt_ = -1.;
  TVector2        *Calo_MET_ElectronEnUp_Mom_;
  Float_t         Calo_MET_ElectronEnUp_sumEt_ = -1.;
  TVector2        *Calo_MET_JetEnDown_Mom_;
  Float_t         Calo_MET_JetEnDown_sumEt_ = -1.;
  TVector2        *Calo_MET_JetEnUp_Mom_;
  Float_t         Calo_MET_JetEnUp_sumEt_ = -1.;
  TVector2        *Calo_MET_JetResDown_Mom_;
  Float_t         Calo_MET_JetResDown_sumEt_ = -1.;
  TVector2        *Calo_MET_JetResUp_Mom_;
  Float_t         Calo_MET_JetResUp_sumEt_ = -1.;
  TVector2        *Calo_MET_MuonEnDown_Mom_;
  Float_t         Calo_MET_MuonEnDown_sumEt_ = -1.;
  TVector2        *Calo_MET_MuonEnUp_Mom_;
  Float_t         Calo_MET_MuonEnUp_sumEt_ = -1.;
  TVector2        *Calo_MET_PhotonEnDown_Mom_;
  Float_t         Calo_MET_PhotonEnDown_sumEt_ = -1.;
  TVector2        *Calo_MET_PhotonEnUp_Mom_;
  Float_t         Calo_MET_PhotonEnUp_sumEt_ = -1.;
  TVector2        *Calo_MET_TauEnDown_Mom_;
  Float_t         Calo_MET_TauEnDown_sumEt_ = -1.;
  TVector2        *Calo_MET_TauEnUp_Mom_;
  Float_t         Calo_MET_TauEnUp_sumEt_ = -1.;
  TVector2        *Calo_MET_UnclusEnDown_Mom_;
  Float_t         Calo_MET_UnclusEnDown_sumEt_ = -1.;
  TVector2        *Calo_MET_UnclusEnUp_Mom_;
  Float_t         Calo_MET_UnclusEnUp_sumEt_ = -1.;

  // GEN MET POINTERS
  TVector2        *Gen_MET_Mom_;
  Float_t         Gen_MET_Inv_Et_ = -1.;
  Float_t         Gen_MET_Inv_EtFrac_ = -1.;
  Float_t         Gen_MET_Muon_Et_ = -1.;
  Float_t         Gen_MET_Muon_EtFrac_ = -1.;
  Float_t         Gen_MET_EM_Chg_Et_ = -1.;
  Float_t         Gen_MET_EM_Chg_EtFrac_ = -1.;
  Float_t         Gen_MET_EM_Neu_Et_ = -1.;
  Float_t         Gen_MET_EM_Neu_EtFrac_ = -1.;
  Float_t         Gen_MET_Had_Chg_Et_ = -1.;
  Float_t         Gen_MET_Had_Chg_EtFrac_ = -1.;
  Float_t         Gen_MET_Had_Neu_Et_ = -1.;
  Float_t         Gen_MET_Had_Neu_EtFrac_ = -1.;
  
  // TYPE 1 CORRECTED MET POINTERS
  TVector2        *Type1_MET_NoShift_Mom_;
  Float_t         Type1_MET_NoShift_sumEt_ = -1.;
  TVector2        *Type1_MET_ElectronEnDown_Mom_;
  Float_t         Type1_MET_ElectronEnDown_sumEt_ = -1.;
  TVector2        *Type1_MET_ElectronEnUp_Mom_;
  Float_t         Type1_MET_ElectronEnUp_sumEt_ = -1.;
  TVector2        *Type1_MET_JetEnDown_Mom_;
  Float_t         Type1_MET_JetEnDown_sumEt_ = -1.;
  TVector2        *Type1_MET_JetEnUp_Mom_;
  Float_t         Type1_MET_JetEnUp_sumEt_ = -1.;
  TVector2        *Type1_MET_JetResDown_Mom_;
  Float_t         Type1_MET_JetResDown_sumEt_ = -1.;
  TVector2        *Type1_MET_JetResUp_Mom_;
  Float_t         Type1_MET_JetResUp_sumEt_ = -1.;
  TVector2        *Type1_MET_MuonEnDown_Mom_;
  Float_t         Type1_MET_MuonEnDown_sumEt_ = -1.;
  TVector2        *Type1_MET_MuonEnUp_Mom_;
  Float_t         Type1_MET_MuonEnUp_sumEt_ = -1.;
  TVector2        *Type1_MET_PhotonEnDown_Mom_;
  Float_t         Type1_MET_PhotonEnDown_sumEt_ = -1.;
  TVector2        *Type1_MET_PhotonEnUp_Mom_;
  Float_t         Type1_MET_PhotonEnUp_sumEt_ = -1.;
  TVector2        *Type1_MET_TauEnDown_Mom_;
  Float_t         Type1_MET_TauEnDown_sumEt_ = -1.;
  TVector2        *Type1_MET_TauEnUp_Mom_;
  Float_t         Type1_MET_TauEnUp_sumEt_ = -1.;
  TVector2        *Type1_MET_UnclusEnDown_Mom_;
  Float_t         Type1_MET_UnclusEnDown_sumEt_ = -1.;
  TVector2        *Type1_MET_UnclusEnUp_Mom_;
  Float_t         Type1_MET_UnclusEnUp_sumEt_ = -1.;
  
  // TYPE XY CORRECTED MET POINTERS
  TVector2        *TypeXY_MET_NoShift_Mom_;
  Float_t         TypeXY_MET_NoShift_sumEt_ = -1.;
  TVector2        *TypeXY_MET_ElectronEnDown_Mom_;
  Float_t         TypeXY_MET_ElectronEnDown_sumEt_ = -1.;
  TVector2        *TypeXY_MET_ElectronEnUp_Mom_;
  Float_t         TypeXY_MET_ElectronEnUp_sumEt_ = -1.;
  TVector2        *TypeXY_MET_JetEnDown_Mom_;
  Float_t         TypeXY_MET_JetEnDown_sumEt_ = -1.;
  TVector2        *TypeXY_MET_JetEnUp_Mom_;
  Float_t         TypeXY_MET_JetEnUp_sumEt_ = -1.;
  TVector2        *TypeXY_MET_JetResDown_Mom_;
  Float_t         TypeXY_MET_JetResDown_sumEt_ = -1.;
  TVector2        *TypeXY_MET_JetResUp_Mom_;
  Float_t         TypeXY_MET_JetResUp_sumEt_ = -1.;
  TVector2        *TypeXY_MET_MuonEnDown_Mom_;
  Float_t         TypeXY_MET_MuonEnDown_sumEt_ = -1.;
  TVector2        *TypeXY_MET_MuonEnUp_Mom_;
  Float_t         TypeXY_MET_MuonEnUp_sumEt_ = -1.;
  TVector2        *TypeXY_MET_PhotonEnDown_Mom_;
  Float_t         TypeXY_MET_PhotonEnDown_sumEt_ = -1.;
  TVector2        *TypeXY_MET_PhotonEnUp_Mom_;
  Float_t         TypeXY_MET_PhotonEnUp_sumEt_ = -1.;
  TVector2        *TypeXY_MET_TauEnDown_Mom_;
  Float_t         TypeXY_MET_TauEnDown_sumEt_ = -1.;
  TVector2        *TypeXY_MET_TauEnUp_Mom_;
  Float_t         TypeXY_MET_TauEnUp_sumEt_ = -1.;
  TVector2        *TypeXY_MET_UnclusEnDown_Mom_;
  Float_t         TypeXY_MET_UnclusEnDown_sumEt_ = -1.;
  TVector2        *TypeXY_MET_UnclusEnUp_Mom_;
  Float_t         TypeXY_MET_UnclusEnUp_sumEt_ = -1.;

  // MET FILTER POINTERS
  Bool_t          Flag_BadChargedCandidateFilter_;
  Bool_t          Flag_BadChargedCandidateSummer16Filter_;
  Bool_t          Flag_BadPFMuonFilter_;
  Bool_t          Flag_BadPFMuonSummer16Filter_;
  Bool_t          Flag_CSCTightHalo2015Filter_;
  Bool_t          Flag_CSCTightHaloFilter_;
  Bool_t          Flag_CSCTightHaloTrkMuUnvetoFilter_;
  Bool_t          Flag_EcalDeadCellBoundaryEnergyFilter_;
  Bool_t          Flag_EcalDeadCellTriggerPrimitiveFilter_;
  Bool_t          Flag_HBHENoiseFilter_;
  Bool_t          Flag_HBHENoiseFilterRun1_;
  Bool_t          Flag_HBHENoiseFilterRun2Loose_;
  Bool_t          Flag_HBHENoiseFilterRun2Tight_;
  Bool_t          Flag_HBHENoiseIsoFilter_;
  Bool_t          Flag_HcalStripHaloFilter_;
  Bool_t          Flag_badMuons_;
  Bool_t          Flag_badTrackerMuons_;
  Bool_t          Flag_chargedHadronTrackResolutionFilter_;
  Bool_t          Flag_collisionEventSelectionPA_;
  Bool_t          Flag_collisionEventSelectionPA_rejectPU_;
  Bool_t          Flag_duplicateMuons_;
  Bool_t          Flag_ecalLaserCorrFilter_;
  Bool_t          Flag_eeBadScFilter_;
  Bool_t          Flag_globalSuperTightHalo2016Filter_;
  Bool_t          Flag_globalTightHalo2016Filter_;
  Bool_t          Flag_goodVertices_;
  Bool_t          Flag_hcalLaserEventFilter_;
  Bool_t          Flag_muonBadTrackFilter_;
  Bool_t          Flag_noBadMuons_;
  Bool_t          Flag_trkPOGFilters_;
  Bool_t          Flag_trkPOG_logErrorTooManyClusters_;
  Bool_t          Flag_trkPOG_manystripclus53X_;
  Bool_t          Flag_trkPOG_toomanystripclus53X_;

  // EVENT INFO BRANCHES
  TBranch        *b_Event_Run;
  TBranch        *b_Event_Lumi;
  TBranch        *b_Event_Bx;
  TBranch        *b_Event_Number;

  // RECO MET BRANCHES
  TBranch        *b_Reco_MET_Mom;
  TBranch        *b_Reco_MET_SigM;
  TBranch        *b_Reco_MET_Sig;
  TBranch        *b_Reco_MET_sumEt;
  TBranch        *b_Reco_MET_mEtSig;

  // PF MET BRANCHES
  TBranch        *b_PF_MET_Mom;
  TBranch        *b_PF_MET_Muon_Et;
  TBranch        *b_PF_MET_Muon_EtFrac;
  TBranch        *b_PF_MET_EM_Chg_Et;
  TBranch        *b_PF_MET_EM_Chg_EtFrac;
  TBranch        *b_PF_MET_EM_Neu_Et;
  TBranch        *b_PF_MET_EM_Neu_EtFrac;
  TBranch        *b_PF_MET_EM_HF_Et;
  TBranch        *b_PF_MET_EM_HF_EtFrac;
  TBranch        *b_PF_MET_Had_Chg_Et;
  TBranch        *b_PF_MET_Had_Chg_EtFrac;
  TBranch        *b_PF_MET_Had_Neu_Et;
  TBranch        *b_PF_MET_Had_Neu_EtFrac;
  TBranch        *b_PF_MET_Had_HF_Et;
  TBranch        *b_PF_MET_Had_HF_EtFrac;
  TBranch        *b_PF_MET_NoShift_Mom;
  TBranch        *b_PF_MET_NoShift_sumEt;
  TBranch        *b_PF_MET_ElectronEnDown_Mom;
  TBranch        *b_PF_MET_ElectronEnDown_sumEt;
  TBranch        *b_PF_MET_ElectronEnUp_Mom;
  TBranch        *b_PF_MET_ElectronEnUp_sumEt;
  TBranch        *b_PF_MET_JetEnDown_Mom;
  TBranch        *b_PF_MET_JetEnDown_sumEt;
  TBranch        *b_PF_MET_JetEnUp_Mom;
  TBranch        *b_PF_MET_JetEnUp_sumEt;
  TBranch        *b_PF_MET_JetResDown_Mom;
  TBranch        *b_PF_MET_JetResDown_sumEt;
  TBranch        *b_PF_MET_JetResUp_Mom;
  TBranch        *b_PF_MET_JetResUp_sumEt;
  TBranch        *b_PF_MET_MuonEnDown_Mom;
  TBranch        *b_PF_MET_MuonEnDown_sumEt;
  TBranch        *b_PF_MET_MuonEnUp_Mom;
  TBranch        *b_PF_MET_MuonEnUp_sumEt;
  TBranch        *b_PF_MET_PhotonEnDown_Mom;
  TBranch        *b_PF_MET_PhotonEnDown_sumEt;
  TBranch        *b_PF_MET_PhotonEnUp_Mom;
  TBranch        *b_PF_MET_PhotonEnUp_sumEt;
  TBranch        *b_PF_MET_TauEnDown_Mom;
  TBranch        *b_PF_MET_TauEnDown_sumEt;
  TBranch        *b_PF_MET_TauEnUp_Mom;
  TBranch        *b_PF_MET_TauEnUp_sumEt;
  TBranch        *b_PF_MET_UnclusEnDown_Mom;
  TBranch        *b_PF_MET_UnclusEnDown_sumEt;
  TBranch        *b_PF_MET_UnclusEnUp_Mom;
  TBranch        *b_PF_MET_UnclusEnUp_sumEt;

  // CALO MET BRANCHES
  TBranch        *b_Calo_MET_Mom;
  TBranch        *b_Calo_MET_Sig;
  TBranch        *b_Calo_MET_mHF_Et;
  TBranch        *b_Calo_MET_mHF_Phi;
  TBranch        *b_Calo_MET_mHF_sumEt;
  TBranch        *b_Calo_MET_pHF_Et;
  TBranch        *b_Calo_MET_pHF_Phi;
  TBranch        *b_Calo_MET_pHF_sumEt;
  TBranch        *b_Calo_MET_EM_EtFrac;
  TBranch        *b_Calo_MET_EM_EB_Et;
  TBranch        *b_Calo_MET_EM_EE_Et;
  TBranch        *b_Calo_MET_EM_HF_Et;
  TBranch        *b_Calo_MET_EM_Tow_maxEt;
  TBranch        *b_Calo_MET_Had_EtFrac;
  TBranch        *b_Calo_MET_Had_HB_Et;
  TBranch        *b_Calo_MET_Had_HE_Et;
  TBranch        *b_Calo_MET_Had_HF_Et;
  TBranch        *b_Calo_MET_Had_HO_Et;
  TBranch        *b_Calo_MET_Had_Tow_maxEt;
  TBranch        *b_Calo_MET_NoShift_Mom;
  TBranch        *b_Calo_MET_NoShift_sumEt;
  TBranch        *b_Calo_MET_ElectronEnDown_Mom;
  TBranch        *b_Calo_MET_ElectronEnDown_sumEt;
  TBranch        *b_Calo_MET_ElectronEnUp_Mom;
  TBranch        *b_Calo_MET_ElectronEnUp_sumEt;
  TBranch        *b_Calo_MET_JetEnDown_Mom;
  TBranch        *b_Calo_MET_JetEnDown_sumEt;
  TBranch        *b_Calo_MET_JetEnUp_Mom;
  TBranch        *b_Calo_MET_JetEnUp_sumEt;
  TBranch        *b_Calo_MET_JetResDown_Mom;
  TBranch        *b_Calo_MET_JetResDown_sumEt;
  TBranch        *b_Calo_MET_JetResUp_Mom;
  TBranch        *b_Calo_MET_JetResUp_sumEt;
  TBranch        *b_Calo_MET_MuonEnDown_Mom;
  TBranch        *b_Calo_MET_MuonEnDown_sumEt;
  TBranch        *b_Calo_MET_MuonEnUp_Mom;
  TBranch        *b_Calo_MET_MuonEnUp_sumEt;
  TBranch        *b_Calo_MET_PhotonEnDown_Mom;
  TBranch        *b_Calo_MET_PhotonEnDown_sumEt;
  TBranch        *b_Calo_MET_PhotonEnUp_Mom;
  TBranch        *b_Calo_MET_PhotonEnUp_sumEt;
  TBranch        *b_Calo_MET_TauEnDown_Mom;
  TBranch        *b_Calo_MET_TauEnDown_sumEt;
  TBranch        *b_Calo_MET_TauEnUp_Mom;
  TBranch        *b_Calo_MET_TauEnUp_sumEt;
  TBranch        *b_Calo_MET_UnclusEnDown_Mom;
  TBranch        *b_Calo_MET_UnclusEnDown_sumEt;
  TBranch        *b_Calo_MET_UnclusEnUp_Mom;
  TBranch        *b_Calo_MET_UnclusEnUp_sumEt;

  // GEN MET BRANCHES
  TBranch        *b_Gen_MET_Mom;
  TBranch        *b_Gen_MET_Inv_Et;
  TBranch        *b_Gen_MET_Inv_EtFrac;
  TBranch        *b_Gen_MET_Muon_Et;
  TBranch        *b_Gen_MET_Muon_EtFrac;
  TBranch        *b_Gen_MET_EM_Chg_Et;
  TBranch        *b_Gen_MET_EM_Chg_EtFrac;
  TBranch        *b_Gen_MET_EM_Neu_Et;
  TBranch        *b_Gen_MET_EM_Neu_EtFrac;
  TBranch        *b_Gen_MET_Had_Chg_Et;
  TBranch        *b_Gen_MET_Had_Chg_EtFrac;
  TBranch        *b_Gen_MET_Had_Neu_Et;
  TBranch        *b_Gen_MET_Had_Neu_EtFrac;

  // TYPE 1 CORRECTED MET BRANCHES
  TBranch        *b_Type1_MET_NoShift_Mom;
  TBranch        *b_Type1_MET_NoShift_sumEt;
  TBranch        *b_Type1_MET_ElectronEnDown_Mom;
  TBranch        *b_Type1_MET_ElectronEnDown_sumEt;
  TBranch        *b_Type1_MET_ElectronEnUp_Mom;
  TBranch        *b_Type1_MET_ElectronEnUp_sumEt;
  TBranch        *b_Type1_MET_JetEnDown_Mom;
  TBranch        *b_Type1_MET_JetEnDown_sumEt;
  TBranch        *b_Type1_MET_JetEnUp_Mom;
  TBranch        *b_Type1_MET_JetEnUp_sumEt;
  TBranch        *b_Type1_MET_JetResDown_Mom;
  TBranch        *b_Type1_MET_JetResDown_sumEt;
  TBranch        *b_Type1_MET_JetResUp_Mom;
  TBranch        *b_Type1_MET_JetResUp_sumEt;
  TBranch        *b_Type1_MET_MuonEnDown_Mom;
  TBranch        *b_Type1_MET_MuonEnDown_sumEt;
  TBranch        *b_Type1_MET_MuonEnUp_Mom;
  TBranch        *b_Type1_MET_MuonEnUp_sumEt;
  TBranch        *b_Type1_MET_PhotonEnDown_Mom;
  TBranch        *b_Type1_MET_PhotonEnDown_sumEt;
  TBranch        *b_Type1_MET_PhotonEnUp_Mom;
  TBranch        *b_Type1_MET_PhotonEnUp_sumEt;
  TBranch        *b_Type1_MET_TauEnDown_Mom;
  TBranch        *b_Type1_MET_TauEnDown_sumEt;
  TBranch        *b_Type1_MET_TauEnUp_Mom;
  TBranch        *b_Type1_MET_TauEnUp_sumEt;
  TBranch        *b_Type1_MET_UnclusEnDown_Mom;
  TBranch        *b_Type1_MET_UnclusEnDown_sumEt;
  TBranch        *b_Type1_MET_UnclusEnUp_Mom;
  TBranch        *b_Type1_MET_UnclusEnUp_sumEt;

  // TYPE XY CORRECTED MET BRANCHES
  TBranch        *b_TypeXY_MET_NoShift_Mom;
  TBranch        *b_TypeXY_MET_NoShift_sumEt;
  TBranch        *b_TypeXY_MET_ElectronEnDown_Mom;
  TBranch        *b_TypeXY_MET_ElectronEnDown_sumEt;
  TBranch        *b_TypeXY_MET_ElectronEnUp_Mom;
  TBranch        *b_TypeXY_MET_ElectronEnUp_sumEt;
  TBranch        *b_TypeXY_MET_JetEnDown_Mom;
  TBranch        *b_TypeXY_MET_JetEnDown_sumEt;
  TBranch        *b_TypeXY_MET_JetEnUp_Mom;
  TBranch        *b_TypeXY_MET_JetEnUp_sumEt;
  TBranch        *b_TypeXY_MET_JetResDown_Mom;
  TBranch        *b_TypeXY_MET_JetResDown_sumEt;
  TBranch        *b_TypeXY_MET_JetResUp_Mom;
  TBranch        *b_TypeXY_MET_JetResUp_sumEt;
  TBranch        *b_TypeXY_MET_MuonEnDown_Mom;
  TBranch        *b_TypeXY_MET_MuonEnDown_sumEt;
  TBranch        *b_TypeXY_MET_MuonEnUp_Mom;
  TBranch        *b_TypeXY_MET_MuonEnUp_sumEt;
  TBranch        *b_TypeXY_MET_PhotonEnDown_Mom;
  TBranch        *b_TypeXY_MET_PhotonEnDown_sumEt;
  TBranch        *b_TypeXY_MET_PhotonEnUp_Mom;
  TBranch        *b_TypeXY_MET_PhotonEnUp_sumEt;
  TBranch        *b_TypeXY_MET_TauEnDown_Mom;
  TBranch        *b_TypeXY_MET_TauEnDown_sumEt;
  TBranch        *b_TypeXY_MET_TauEnUp_Mom;
  TBranch        *b_TypeXY_MET_TauEnUp_sumEt;
  TBranch        *b_TypeXY_MET_UnclusEnDown_Mom;
  TBranch        *b_TypeXY_MET_UnclusEnDown_sumEt;
  TBranch        *b_TypeXY_MET_UnclusEnUp_Mom;
  TBranch        *b_TypeXY_MET_UnclusEnUp_sumEt;

  // MET FILTER BRANCHES
  TBranch        *b_Flag_BadChargedCandidateFilter;
  TBranch        *b_Flag_BadChargedCandidateSummer16Filter;
  TBranch        *b_Flag_BadPFMuonFilter;
  TBranch        *b_Flag_BadPFMuonSummer16Filter;
  TBranch        *b_Flag_CSCTightHalo2015Filter;
  TBranch        *b_Flag_CSCTightHaloFilter;
  TBranch        *b_Flag_CSCTightHaloTrkMuUnvetoFilter;
  TBranch        *b_Flag_EcalDeadCellBoundaryEnergyFilter;
  TBranch        *b_Flag_EcalDeadCellTriggerPrimitiveFilter;
  TBranch        *b_Flag_HBHENoiseFilter;
  TBranch        *b_Flag_HBHENoiseFilterRun1;
  TBranch        *b_Flag_HBHENoiseFilterRun2Loose;
  TBranch        *b_Flag_HBHENoiseFilterRun2Tight;
  TBranch        *b_Flag_HBHENoiseIsoFilter;
  TBranch        *b_Flag_HcalStripHaloFilter;
  TBranch        *b_Flag_badMuons;
  TBranch        *b_Flag_badTrackerMuons;
  TBranch        *b_Flag_chargedHadronTrackResolutionFilter;
  TBranch        *b_Flag_collisionEventSelectionPA;
  TBranch        *b_Flag_collisionEventSelectionPA_rejectPU;
  TBranch        *b_Flag_duplicateMuons;
  TBranch        *b_Flag_ecalLaserCorrFilter;
  TBranch        *b_Flag_eeBadScFilter;
  TBranch        *b_Flag_globalSuperTightHalo2016Filter;
  TBranch        *b_Flag_globalTightHalo2016Filter;
  TBranch        *b_Flag_goodVertices;
  TBranch        *b_Flag_hcalLaserEventFilter;
  TBranch        *b_Flag_muonBadTrackFilter;
  TBranch        *b_Flag_noBadMuons;
  TBranch        *b_Flag_trkPOGFilters;
  TBranch        *b_Flag_trkPOG_logErrorTooManyClusters;
  TBranch        *b_Flag_trkPOG_manystripclus53X;
  TBranch        *b_Flag_trkPOG_toomanystripclus53X;
};

HiMETTree::HiMETTree() : fChain_(0)
{
}

HiMETTree::~HiMETTree()
{
  if (fChain_) fChain_->GetCurrentFile();
}

Bool_t HiMETTree::GetTree(const std::string& fileName, TTree* tree, const std::string& treeName)
{
  // Open the input files
  TFile *f = TFile::Open(fileName.c_str());
  if (!f || !f->IsOpen()) return false;
  // Extract the input TTrees
  fChainM_.clear();
  TDirectory * dir;
  if (fileName.find("root://")!=std::string::npos) dir = (TDirectory*)f->Get(treeName.c_str());
  else dir = (TDirectory*)f->Get((fileName+":/"+treeName).c_str());
  if (!dir) return false;
  if (dir->GetListOfKeys()->Contains("MET_Event")  ) dir->GetObject("MET_Event",  fChainM_["Event"]  );
  if (dir->GetListOfKeys()->Contains("MET_Reco")   ) dir->GetObject("MET_Reco",   fChainM_["Reco"]   );
  if (dir->GetListOfKeys()->Contains("MET_PF")     ) dir->GetObject("MET_PF",     fChainM_["PF"]     );
  if (dir->GetListOfKeys()->Contains("MET_Calo")   ) dir->GetObject("MET_Calo",   fChainM_["Calo"]   );
  if (dir->GetListOfKeys()->Contains("MET_Gen")    ) dir->GetObject("MET_Gen",    fChainM_["Gen"]    );
  if (dir->GetListOfKeys()->Contains("MET_Type1")  ) dir->GetObject("MET_Type1",  fChainM_["Type1"]  );
  if (dir->GetListOfKeys()->Contains("MET_TypeXY") ) dir->GetObject("MET_TypeXY", fChainM_["TypeXY"] );
  if (dir->GetListOfKeys()->Contains("MET_Filter") ) dir->GetObject("MET_Filter", fChainM_["Filter"] );
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
    }
  }
  if (fChain_ == 0) return false;
  return true;
}

Int_t HiMETTree::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  entry_ = entry;
  if (LoadTree(entry_) < 0) return -1;
  Clear();
  return LoadEntry();
}

Long64_t HiMETTree::LoadTree(Long64_t entry)
{
  // Set the environment to read one entry
  if (!fChain_) return -5;
  Long64_t centry = fChain_->LoadTree(entry);
  return centry;
}

void HiMETTree::SetBranch(const std::string& n)
{
  std::string type = n.substr(0, n.find("_"));
  if (type=="Flag") { type = "Filter"; }
  if ( fChainM_.count(type.c_str())>0 && fChainM_[type.c_str()]->GetBranch(n.c_str()) && (fChainM_[type.c_str()]->GetBranchStatus(n.c_str()) == 0) ) {
    fChainM_[type.c_str()]->SetBranchStatus(n.c_str(), 1);
    LoadEntry(); // Needed for the first entry
  }
}


void HiMETTree::InitTree(void)
{
  // INITIALIZE RECO MET POINTERS
  Reco_MET_Mom_ = 0;
  Reco_MET_SigM_ = 0;

  // INITIALIZE PF MET POINTERS
  PF_MET_Mom_ = 0;
  PF_MET_NoShift_Mom_ = 0;
  PF_MET_ElectronEnDown_Mom_ = 0;
  PF_MET_ElectronEnUp_Mom_ = 0;
  PF_MET_JetEnDown_Mom_ = 0;
  PF_MET_JetEnUp_Mom_ = 0;
  PF_MET_JetResDown_Mom_ = 0;
  PF_MET_JetResUp_Mom_ = 0;
  PF_MET_MuonEnDown_Mom_ = 0;
  PF_MET_MuonEnUp_Mom_ = 0;
  PF_MET_PhotonEnDown_Mom_ = 0;
  PF_MET_PhotonEnUp_Mom_ = 0;
  PF_MET_TauEnDown_Mom_ = 0;
  PF_MET_TauEnUp_Mom_ = 0;
  PF_MET_UnclusEnDown_Mom_ = 0;
  PF_MET_UnclusEnUp_Mom_ = 0;
  
  // INITIALIZE CALO MET POINTERS
  Calo_MET_Mom_ = 0;
  Calo_MET_NoShift_Mom_ = 0;
  Calo_MET_ElectronEnDown_Mom_ = 0;
  Calo_MET_ElectronEnUp_Mom_ = 0;
  Calo_MET_JetEnDown_Mom_ = 0;
  Calo_MET_JetEnUp_Mom_ = 0;
  Calo_MET_JetResDown_Mom_ = 0;
  Calo_MET_JetResUp_Mom_ = 0;
  Calo_MET_MuonEnDown_Mom_ = 0;
  Calo_MET_MuonEnUp_Mom_ = 0;
  Calo_MET_PhotonEnDown_Mom_ = 0;
  Calo_MET_PhotonEnUp_Mom_ = 0;
  Calo_MET_TauEnDown_Mom_ = 0;
  Calo_MET_TauEnUp_Mom_ = 0;
  Calo_MET_UnclusEnDown_Mom_ = 0;
  Calo_MET_UnclusEnUp_Mom_ = 0;

  // INITIALIZE GEN MET POINTERS
  Gen_MET_Mom_ = 0;
  
  // INITIALIZE TYPE 1 CORRECTED MET POINTERS
  Type1_MET_NoShift_Mom_ = 0;
  Type1_MET_ElectronEnDown_Mom_ = 0;
  Type1_MET_ElectronEnUp_Mom_ = 0;
  Type1_MET_JetEnDown_Mom_ = 0;
  Type1_MET_JetEnUp_Mom_ = 0;
  Type1_MET_JetResDown_Mom_ = 0;
  Type1_MET_JetResUp_Mom_ = 0;
  Type1_MET_MuonEnDown_Mom_ = 0;
  Type1_MET_MuonEnUp_Mom_ = 0;
  Type1_MET_PhotonEnDown_Mom_ = 0;
  Type1_MET_PhotonEnUp_Mom_ = 0;
  Type1_MET_TauEnDown_Mom_ = 0;
  Type1_MET_TauEnUp_Mom_ = 0;
  Type1_MET_UnclusEnDown_Mom_ = 0;
  Type1_MET_UnclusEnUp_Mom_ = 0;
  
  // INITIALIZE TYPE XY CORRECTED MET POINTERS
  TypeXY_MET_NoShift_Mom_ = 0;
  TypeXY_MET_ElectronEnDown_Mom_ = 0;
  TypeXY_MET_ElectronEnUp_Mom_ = 0;
  TypeXY_MET_JetEnDown_Mom_ = 0;
  TypeXY_MET_JetEnUp_Mom_ = 0;
  TypeXY_MET_JetResDown_Mom_ = 0;
  TypeXY_MET_JetResUp_Mom_ = 0;
  TypeXY_MET_MuonEnDown_Mom_ = 0;
  TypeXY_MET_MuonEnUp_Mom_ = 0;
  TypeXY_MET_PhotonEnDown_Mom_ = 0;
  TypeXY_MET_PhotonEnUp_Mom_ = 0;
  TypeXY_MET_TauEnDown_Mom_ = 0;
  TypeXY_MET_TauEnUp_Mom_ = 0;
  TypeXY_MET_UnclusEnDown_Mom_ = 0;
  TypeXY_MET_UnclusEnUp_Mom_ = 0;

  if (fChainM_.size()==0) return;

  // SET EVENT INFO BRANCHES
  if (fChainM_.count("Event")>0) {
    if (fChainM_["Event"]->GetBranch("Event_Run"))                        fChainM_["Event"]->SetBranchAddress("Event_Run", &Event_Run_, &b_Event_Run);
    if (fChainM_["Event"]->GetBranch("Event_Lumi"))                       fChainM_["Event"]->SetBranchAddress("Event_Lumi", &Event_Lumi_, &b_Event_Lumi);
    if (fChainM_["Event"]->GetBranch("Event_Bx"))                         fChainM_["Event"]->SetBranchAddress("Event_Bx", &Event_Bx_, &b_Event_Bx);
    if (fChainM_["Event"]->GetBranch("Event_Number"))                     fChainM_["Event"]->SetBranchAddress("Event_Number", &Event_Number_, &b_Event_Number);
    // Set All Branches to Status 0
    fChainM_["Event"]->SetBranchStatus("*",0);
  }

  // SET RECO MET BRANCHES
  if (fChainM_.count("Reco")>0) {
    if (fChainM_["Reco"]->GetBranch("Reco_MET_Mom"))                      fChainM_["Reco"]->SetBranchAddress("Reco_MET_Mom", &Reco_MET_Mom_, &b_Reco_MET_Mom);
    if (fChainM_["Reco"]->GetBranch("Reco_MET_SigM"))                     fChainM_["Reco"]->SetBranchAddress("Reco_MET_SigM", &Reco_MET_SigM_, &b_Reco_MET_SigM);
    if (fChainM_["Reco"]->GetBranch("Reco_MET_Sig"))                      fChainM_["Reco"]->SetBranchAddress("Reco_MET_Sig", &Reco_MET_Sig_, &b_Reco_MET_Sig);
    if (fChainM_["Reco"]->GetBranch("Reco_MET_sumEt"))                    fChainM_["Reco"]->SetBranchAddress("Reco_MET_sumEt", &Reco_MET_sumEt_, &b_Reco_MET_sumEt);
    if (fChainM_["Reco"]->GetBranch("Reco_MET_mEtSig"))                   fChainM_["Reco"]->SetBranchAddress("Reco_MET_mEtSig", &Reco_MET_mEtSig_, &b_Reco_MET_mEtSig);
    // Set All Branches to Status 0
    fChainM_["Reco"]->SetBranchStatus("*",0);
  }

  // SET PF MET BRANCHES
  if (fChainM_.count("PF")>0) {
    if (fChainM_["PF"]->GetBranch("PF_MET_Mom"))                          fChainM_["PF"]->SetBranchAddress("PF_MET_Mom", &PF_MET_Mom_, &b_PF_MET_Mom);
    if (fChainM_["PF"]->GetBranch("PF_MET_Muon_Et"))                      fChainM_["PF"]->SetBranchAddress("PF_MET_Muon_Et", &PF_MET_Muon_Et_, &b_PF_MET_Muon_Et);
    if (fChainM_["PF"]->GetBranch("PF_MET_Muon_EtFrac"))                  fChainM_["PF"]->SetBranchAddress("PF_MET_Muon_EtFrac", &PF_MET_Muon_EtFrac_, &b_PF_MET_Muon_EtFrac);
    if (fChainM_["PF"]->GetBranch("PF_MET_Chg_Et"))                       fChainM_["PF"]->SetBranchAddress("PF_MET_EM_Chg_Et", &PF_MET_EM_Chg_Et_, &b_PF_MET_EM_Chg_Et);
    if (fChainM_["PF"]->GetBranch("PF_MET_EM_Chg_EtFrac"))                fChainM_["PF"]->SetBranchAddress("PF_MET_EM_Chg_EtFrac", &PF_MET_EM_Chg_EtFrac_, &b_PF_MET_EM_Chg_EtFrac);
    if (fChainM_["PF"]->GetBranch("PF_MET_EM_Neu_Et"))                    fChainM_["PF"]->SetBranchAddress("PF_MET_EM_Neu_Et", &PF_MET_EM_Neu_Et_, &b_PF_MET_EM_Neu_Et);
    if (fChainM_["PF"]->GetBranch("PF_MET_EM_Neu_EtFrac"))                fChainM_["PF"]->SetBranchAddress("PF_MET_EM_Neu_EtFrac", &PF_MET_EM_Neu_EtFrac_, &b_PF_MET_EM_Neu_EtFrac);
    if (fChainM_["PF"]->GetBranch("PF_MET_EM_HF_Et"))                     fChainM_["PF"]->SetBranchAddress("PF_MET_EM_HF_Et", &PF_MET_EM_HF_Et_, &b_PF_MET_EM_HF_Et);
    if (fChainM_["PF"]->GetBranch("PF_MET_EM_HF_EtFrac"))                 fChainM_["PF"]->SetBranchAddress("PF_MET_EM_HF_EtFrac", &PF_MET_EM_HF_EtFrac_, &b_PF_MET_EM_HF_EtFrac);
    if (fChainM_["PF"]->GetBranch("PF_MET_Had_Chg_Et"))                   fChainM_["PF"]->SetBranchAddress("PF_MET_Had_Chg_Et", &PF_MET_Had_Chg_Et_, &b_PF_MET_Had_Chg_Et);
    if (fChainM_["PF"]->GetBranch("PF_MET_Had_Chg_EtFrac"))               fChainM_["PF"]->SetBranchAddress("PF_MET_Had_Chg_EtFrac", &PF_MET_Had_Chg_EtFrac_, &b_PF_MET_Had_Chg_EtFrac);
    if (fChainM_["PF"]->GetBranch("PF_MET_Had_Neu_Et"))                   fChainM_["PF"]->SetBranchAddress("PF_MET_Had_Neu_Et", &PF_MET_Had_Neu_Et_, &b_PF_MET_Had_Neu_Et);
    if (fChainM_["PF"]->GetBranch("PF_MET_Had_Neu_EtFrac"))               fChainM_["PF"]->SetBranchAddress("PF_MET_Had_Neu_EtFrac", &PF_MET_Had_Neu_EtFrac_, &b_PF_MET_Had_Neu_EtFrac);
    if (fChainM_["PF"]->GetBranch("PF_MET_Had_HF_Et"))                    fChainM_["PF"]->SetBranchAddress("PF_MET_Had_HF_Et", &PF_MET_Had_HF_Et_, &b_PF_MET_Had_HF_Et);
    if (fChainM_["PF"]->GetBranch("PF_MET_Had_HF_EtFrac"))                fChainM_["PF"]->SetBranchAddress("PF_MET_Had_HF_EtFrac", &PF_MET_Had_HF_EtFrac_, &b_PF_MET_Had_HF_EtFrac);
    if (fChainM_["PF"]->GetBranch("PF_MET_NoShift_Mom"))                  fChainM_["PF"]->SetBranchAddress("PF_MET_NoShift_Mom", &PF_MET_NoShift_Mom_, &b_PF_MET_NoShift_Mom);
    if (fChainM_["PF"]->GetBranch("PF_MET_NoShift_sumEt"))                fChainM_["PF"]->SetBranchAddress("PF_MET_NoShift_sumEt", &PF_MET_NoShift_sumEt_, &b_PF_MET_NoShift_sumEt);
    if (fChainM_["PF"]->GetBranch("PF_MET_ElectronEnDown_Mom"))           fChainM_["PF"]->SetBranchAddress("PF_MET_ElectronEnDown_Mom", &PF_MET_ElectronEnDown_Mom_, &b_PF_MET_ElectronEnDown_Mom);
    if (fChainM_["PF"]->GetBranch("PF_MET_ElectronEnDown_sumEt"))         fChainM_["PF"]->SetBranchAddress("PF_MET_ElectronEnDown_sumEt", &PF_MET_ElectronEnDown_sumEt_, &b_PF_MET_ElectronEnDown_sumEt);
    if (fChainM_["PF"]->GetBranch("PF_MET_ElectronEnUp_Mom"))             fChainM_["PF"]->SetBranchAddress("PF_MET_ElectronEnUp_Mom", &PF_MET_ElectronEnUp_Mom_, &b_PF_MET_ElectronEnUp_Mom);
    if (fChainM_["PF"]->GetBranch("PF_MET_ElectronEnUp_sumEt"))           fChainM_["PF"]->SetBranchAddress("PF_MET_ElectronEnUp_sumEt", &PF_MET_ElectronEnUp_sumEt_, &b_PF_MET_ElectronEnUp_sumEt);
    if (fChainM_["PF"]->GetBranch("PF_MET_JetEnDown_Mom"))                fChainM_["PF"]->SetBranchAddress("PF_MET_JetEnDown_Mom", &PF_MET_JetEnDown_Mom_, &b_PF_MET_JetEnDown_Mom);
    if (fChainM_["PF"]->GetBranch("PF_MET_JetEnDown_sumEt"))              fChainM_["PF"]->SetBranchAddress("PF_MET_JetEnDown_sumEt", &PF_MET_JetEnDown_sumEt_, &b_PF_MET_JetEnDown_sumEt);
    if (fChainM_["PF"]->GetBranch("PF_MET_JetEnUp_Mom"))                  fChainM_["PF"]->SetBranchAddress("PF_MET_JetEnUp_Mom", &PF_MET_JetEnUp_Mom_, &b_PF_MET_JetEnUp_Mom);
    if (fChainM_["PF"]->GetBranch("PF_MET_JetEnUp_sumEt"))                fChainM_["PF"]->SetBranchAddress("PF_MET_JetEnUp_sumEt", &PF_MET_JetEnUp_sumEt_, &b_PF_MET_JetEnUp_sumEt);
    if (fChainM_["PF"]->GetBranch("PF_MET_JetResDown_Mom"))               fChainM_["PF"]->SetBranchAddress("PF_MET_JetResDown_Mom", &PF_MET_JetResDown_Mom_, &b_PF_MET_JetResDown_Mom);
    if (fChainM_["PF"]->GetBranch("PF_MET_JetResDown_sumEt"))             fChainM_["PF"]->SetBranchAddress("PF_MET_JetResDown_sumEt", &PF_MET_JetResDown_sumEt_, &b_PF_MET_JetResDown_sumEt);
    if (fChainM_["PF"]->GetBranch("PF_MET_JetResUp_Mom"))                 fChainM_["PF"]->SetBranchAddress("PF_MET_JetResUp_Mom", &PF_MET_JetResUp_Mom_, &b_PF_MET_JetResUp_Mom);
    if (fChainM_["PF"]->GetBranch("PF_MET_JetResUp_sumEt"))               fChainM_["PF"]->SetBranchAddress("PF_MET_JetResUp_sumEt", &PF_MET_JetResUp_sumEt_, &b_PF_MET_JetResUp_sumEt);
    if (fChainM_["PF"]->GetBranch("PF_MET_MuonEnDown_Mom"))               fChainM_["PF"]->SetBranchAddress("PF_MET_MuonEnDown_Mom", &PF_MET_MuonEnDown_Mom_, &b_PF_MET_MuonEnDown_Mom);
    if (fChainM_["PF"]->GetBranch("PF_MET_MuonEnDown_sumEt"))             fChainM_["PF"]->SetBranchAddress("PF_MET_MuonEnDown_sumEt", &PF_MET_MuonEnDown_sumEt_, &b_PF_MET_MuonEnDown_sumEt);
    if (fChainM_["PF"]->GetBranch("PF_MET_MuonEnUp_Mom"))                 fChainM_["PF"]->SetBranchAddress("PF_MET_MuonEnUp_Mom", &PF_MET_MuonEnUp_Mom_, &b_PF_MET_MuonEnUp_Mom);
    if (fChainM_["PF"]->GetBranch("PF_MET_MuonEnUp_sumEt"))               fChainM_["PF"]->SetBranchAddress("PF_MET_MuonEnUp_sumEt", &PF_MET_MuonEnUp_sumEt_, &b_PF_MET_MuonEnUp_sumEt);
    if (fChainM_["PF"]->GetBranch("PF_MET_PhotonEnDown_Mom"))             fChainM_["PF"]->SetBranchAddress("PF_MET_PhotonEnDown_Mom", &PF_MET_PhotonEnDown_Mom_, &b_PF_MET_PhotonEnDown_Mom);
    if (fChainM_["PF"]->GetBranch("PF_MET_PhotonEnDown_sumEt"))           fChainM_["PF"]->SetBranchAddress("PF_MET_PhotonEnDown_sumEt", &PF_MET_PhotonEnDown_sumEt_, &b_PF_MET_PhotonEnDown_sumEt);
    if (fChainM_["PF"]->GetBranch("PF_MET_PhotonEnUp_Mom"))               fChainM_["PF"]->SetBranchAddress("PF_MET_PhotonEnUp_Mom", &PF_MET_PhotonEnUp_Mom_, &b_PF_MET_PhotonEnUp_Mom);
    if (fChainM_["PF"]->GetBranch("PF_MET_PhotonEnUp_sumEt"))             fChainM_["PF"]->SetBranchAddress("PF_MET_PhotonEnUp_sumEt", &PF_MET_PhotonEnUp_sumEt_, &b_PF_MET_PhotonEnUp_sumEt);
    if (fChainM_["PF"]->GetBranch("PF_MET_TauEnDown_Mom"))                fChainM_["PF"]->SetBranchAddress("PF_MET_TauEnDown_Mom", &PF_MET_TauEnDown_Mom_, &b_PF_MET_TauEnDown_Mom);
    if (fChainM_["PF"]->GetBranch("PF_MET_TauEnDown_sumEt"))              fChainM_["PF"]->SetBranchAddress("PF_MET_TauEnDown_sumEt", &PF_MET_TauEnDown_sumEt_, &b_PF_MET_TauEnDown_sumEt);
    if (fChainM_["PF"]->GetBranch("PF_MET_TauEnUp_Mom"))                  fChainM_["PF"]->SetBranchAddress("PF_MET_TauEnUp_Mom", &PF_MET_TauEnUp_Mom_, &b_PF_MET_TauEnUp_Mom);
    if (fChainM_["PF"]->GetBranch("PF_MET_TauEnUp_sumEt"))                fChainM_["PF"]->SetBranchAddress("PF_MET_TauEnUp_sumEt", &PF_MET_TauEnUp_sumEt_, &b_PF_MET_TauEnUp_sumEt);
    if (fChainM_["PF"]->GetBranch("PF_MET_UnclusEnDown_Mom"))             fChainM_["PF"]->SetBranchAddress("PF_MET_UnclusEnDown_Mom", &PF_MET_UnclusEnDown_Mom_, &b_PF_MET_UnclusEnDown_Mom);
    if (fChainM_["PF"]->GetBranch("PF_MET_UnclusEnDown_sumEt"))           fChainM_["PF"]->SetBranchAddress("PF_MET_UnclusEnDown_sumEt", &PF_MET_UnclusEnDown_sumEt_, &b_PF_MET_UnclusEnDown_sumEt);
    if (fChainM_["PF"]->GetBranch("PF_MET_UnclusEnUp_Mom"))               fChainM_["PF"]->SetBranchAddress("PF_MET_UnclusEnUp_Mom", &PF_MET_UnclusEnUp_Mom_, &b_PF_MET_UnclusEnUp_Mom);
    if (fChainM_["PF"]->GetBranch("PF_MET_UnclusEnUp_sumEt"))             fChainM_["PF"]->SetBranchAddress("PF_MET_UnclusEnUp_sumEt", &PF_MET_UnclusEnUp_sumEt_, &b_PF_MET_UnclusEnUp_sumEt);
    // Set All Branches to Status 0
    fChainM_["PF"]->SetBranchStatus("*",0);
  }

  // SET CALO MET BRANCHES
  if (fChainM_.count("Calo")>0) {
    if (fChainM_["Calo"]->GetBranch("Calo_MET_Mom"))                      fChainM_["Calo"]->SetBranchAddress("Calo_MET_Mom", &Calo_MET_Mom_, &b_Calo_MET_Mom);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_Sig"))                      fChainM_["Calo"]->SetBranchAddress("Calo_MET_Sig", &Calo_MET_Sig_, &b_Calo_MET_Sig);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_mHF_Et"))                   fChainM_["Calo"]->SetBranchAddress("Calo_MET_mHF_Et", &Calo_MET_mHF_Et_, &b_Calo_MET_mHF_Et);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_mHF_Phi"))                  fChainM_["Calo"]->SetBranchAddress("Calo_MET_mHF_Phi", &Calo_MET_mHF_Phi_, &b_Calo_MET_mHF_Phi);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_mHF_sumEt"))                fChainM_["Calo"]->SetBranchAddress("Calo_MET_mHF_sumEt", &Calo_MET_mHF_sumEt_, &b_Calo_MET_mHF_sumEt);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_pHF_Et"))                   fChainM_["Calo"]->SetBranchAddress("Calo_MET_pHF_Et", &Calo_MET_pHF_Et_, &b_Calo_MET_pHF_Et);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_pHF_Phi"))                  fChainM_["Calo"]->SetBranchAddress("Calo_MET_pHF_Phi", &Calo_MET_pHF_Phi_, &b_Calo_MET_pHF_Phi);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_pHF_sumEt"))                fChainM_["Calo"]->SetBranchAddress("Calo_MET_pHF_sumEt", &Calo_MET_pHF_sumEt_, &b_Calo_MET_pHF_sumEt);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_EM_EtFrac"))                fChainM_["Calo"]->SetBranchAddress("Calo_MET_EM_EtFrac", &Calo_MET_EM_EtFrac_, &b_Calo_MET_EM_EtFrac);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_EM_EB_Et"))                 fChainM_["Calo"]->SetBranchAddress("Calo_MET_EM_EB_Et", &Calo_MET_EM_EB_Et_, &b_Calo_MET_EM_EB_Et);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_EM_EE_Et"))                 fChainM_["Calo"]->SetBranchAddress("Calo_MET_EM_EE_Et", &Calo_MET_EM_EE_Et_, &b_Calo_MET_EM_EE_Et);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_EM_HF_Et"))                 fChainM_["Calo"]->SetBranchAddress("Calo_MET_EM_HF_Et", &Calo_MET_EM_HF_Et_, &b_Calo_MET_EM_HF_Et);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_EM_Tow_maxEt"))             fChainM_["Calo"]->SetBranchAddress("Calo_MET_EM_Tow_maxEt", &Calo_MET_EM_Tow_maxEt_, &b_Calo_MET_EM_Tow_maxEt);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_Had_EtFrac"))               fChainM_["Calo"]->SetBranchAddress("Calo_MET_Had_EtFrac", &Calo_MET_Had_EtFrac_, &b_Calo_MET_Had_EtFrac);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_Had_HB_Et"))                fChainM_["Calo"]->SetBranchAddress("Calo_MET_Had_HB_Et", &Calo_MET_Had_HB_Et_, &b_Calo_MET_Had_HB_Et);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_Had_HE_Et"))                fChainM_["Calo"]->SetBranchAddress("Calo_MET_Had_HE_Et", &Calo_MET_Had_HE_Et_, &b_Calo_MET_Had_HE_Et);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_Had_HF_Et"))                fChainM_["Calo"]->SetBranchAddress("Calo_MET_Had_HF_Et", &Calo_MET_Had_HF_Et_, &b_Calo_MET_Had_HF_Et);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_Had_HO_Et"))                fChainM_["Calo"]->SetBranchAddress("Calo_MET_Had_HO_Et", &Calo_MET_Had_HO_Et_, &b_Calo_MET_Had_HO_Et);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_Had_Tow_maxEt"))            fChainM_["Calo"]->SetBranchAddress("Calo_MET_Had_Tow_maxEt", &Calo_MET_Had_Tow_maxEt_, &b_Calo_MET_Had_Tow_maxEt);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_NoShift_Mom"))              fChainM_["Calo"]->SetBranchAddress("Calo_MET_NoShift_Mom", &Calo_MET_NoShift_Mom_, &b_Calo_MET_NoShift_Mom);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_NoShift_sumEt"))            fChainM_["Calo"]->SetBranchAddress("Calo_MET_NoShift_sumEt", &Calo_MET_NoShift_sumEt_, &b_Calo_MET_NoShift_sumEt);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_ElectronEnDown_Mom"))       fChainM_["Calo"]->SetBranchAddress("Calo_MET_ElectronEnDown_Mom", &Calo_MET_ElectronEnDown_Mom_, &b_Calo_MET_ElectronEnDown_Mom);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_ElectronEnDown_sumEt"))     fChainM_["Calo"]->SetBranchAddress("Calo_MET_ElectronEnDown_sumEt", &Calo_MET_ElectronEnDown_sumEt_, &b_Calo_MET_ElectronEnDown_sumEt);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_ElectronEnUp_Mom"))         fChainM_["Calo"]->SetBranchAddress("Calo_MET_ElectronEnUp_Mom", &Calo_MET_ElectronEnUp_Mom_, &b_Calo_MET_ElectronEnUp_Mom);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_ElectronEnUp_sumEt"))       fChainM_["Calo"]->SetBranchAddress("Calo_MET_ElectronEnUp_sumEt", &Calo_MET_ElectronEnUp_sumEt_, &b_Calo_MET_ElectronEnUp_sumEt);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_JetEnDown_Mom"))            fChainM_["Calo"]->SetBranchAddress("Calo_MET_JetEnDown_Mom", &Calo_MET_JetEnDown_Mom_, &b_Calo_MET_JetEnDown_Mom);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_JetEnDown_sumEt"))          fChainM_["Calo"]->SetBranchAddress("Calo_MET_JetEnDown_sumEt", &Calo_MET_JetEnDown_sumEt_, &b_Calo_MET_JetEnDown_sumEt);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_JetEnUp_Mom"))              fChainM_["Calo"]->SetBranchAddress("Calo_MET_JetEnUp_Mom", &Calo_MET_JetEnUp_Mom_, &b_Calo_MET_JetEnUp_Mom);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_JetEnUp_sumEt"))            fChainM_["Calo"]->SetBranchAddress("Calo_MET_JetEnUp_sumEt", &Calo_MET_JetEnUp_sumEt_, &b_Calo_MET_JetEnUp_sumEt);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_JetResDown_Mom"))           fChainM_["Calo"]->SetBranchAddress("Calo_MET_JetResDown_Mom", &Calo_MET_JetResDown_Mom_, &b_Calo_MET_JetResDown_Mom);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_JetResDown_sumEt"))         fChainM_["Calo"]->SetBranchAddress("Calo_MET_JetResDown_sumEt", &Calo_MET_JetResDown_sumEt_, &b_Calo_MET_JetResDown_sumEt);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_JetResUp_Mom"))             fChainM_["Calo"]->SetBranchAddress("Calo_MET_JetResUp_Mom", &Calo_MET_JetResUp_Mom_, &b_Calo_MET_JetResUp_Mom);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_JetResUp_sumEt"))           fChainM_["Calo"]->SetBranchAddress("Calo_MET_JetResUp_sumEt", &Calo_MET_JetResUp_sumEt_, &b_Calo_MET_JetResUp_sumEt);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_MuonEnDown_Mom"))           fChainM_["Calo"]->SetBranchAddress("Calo_MET_MuonEnDown_Mom", &Calo_MET_MuonEnDown_Mom_, &b_Calo_MET_MuonEnDown_Mom);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_MuonEnDown_sumEt"))         fChainM_["Calo"]->SetBranchAddress("Calo_MET_MuonEnDown_sumEt", &Calo_MET_MuonEnDown_sumEt_, &b_Calo_MET_MuonEnDown_sumEt);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_MuonEnUp_Mom"))             fChainM_["Calo"]->SetBranchAddress("Calo_MET_MuonEnUp_Mom", &Calo_MET_MuonEnUp_Mom_, &b_Calo_MET_MuonEnUp_Mom);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_MuonEnUp_sumEt"))           fChainM_["Calo"]->SetBranchAddress("Calo_MET_MuonEnUp_sumEt", &Calo_MET_MuonEnUp_sumEt_, &b_Calo_MET_MuonEnUp_sumEt);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_PhotonEnDown_Mom"))         fChainM_["Calo"]->SetBranchAddress("Calo_MET_PhotonEnDown_Mom", &Calo_MET_PhotonEnDown_Mom_, &b_Calo_MET_PhotonEnDown_Mom);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_PhotonEnDown_sumEt"))       fChainM_["Calo"]->SetBranchAddress("Calo_MET_PhotonEnDown_sumEt", &Calo_MET_PhotonEnDown_sumEt_, &b_Calo_MET_PhotonEnDown_sumEt);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_PhotonEnUp_Mom"))           fChainM_["Calo"]->SetBranchAddress("Calo_MET_PhotonEnUp_Mom", &Calo_MET_PhotonEnUp_Mom_, &b_Calo_MET_PhotonEnUp_Mom);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_PhotonEnUp_sumEt"))         fChainM_["Calo"]->SetBranchAddress("Calo_MET_PhotonEnUp_sumEt", &Calo_MET_PhotonEnUp_sumEt_, &b_Calo_MET_PhotonEnUp_sumEt);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_TauEnDown_Mom"))            fChainM_["Calo"]->SetBranchAddress("Calo_MET_TauEnDown_Mom", &Calo_MET_TauEnDown_Mom_, &b_Calo_MET_TauEnDown_Mom);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_TauEnDown_sumEt"))          fChainM_["Calo"]->SetBranchAddress("Calo_MET_TauEnDown_sumEt", &Calo_MET_TauEnDown_sumEt_, &b_Calo_MET_TauEnDown_sumEt);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_TauEnUp_Mom"))              fChainM_["Calo"]->SetBranchAddress("Calo_MET_TauEnUp_Mom", &Calo_MET_TauEnUp_Mom_, &b_Calo_MET_TauEnUp_Mom);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_TauEnUp_sumEt"))            fChainM_["Calo"]->SetBranchAddress("Calo_MET_TauEnUp_sumEt", &Calo_MET_TauEnUp_sumEt_, &b_Calo_MET_TauEnUp_sumEt);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_UnclusEnDown_Mom"))         fChainM_["Calo"]->SetBranchAddress("Calo_MET_UnclusEnDown_Mom", &Calo_MET_UnclusEnDown_Mom_, &b_Calo_MET_UnclusEnDown_Mom);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_UnclusEnDown_sumEt"))       fChainM_["Calo"]->SetBranchAddress("Calo_MET_UnclusEnDown_sumEt", &Calo_MET_UnclusEnDown_sumEt_, &b_Calo_MET_UnclusEnDown_sumEt);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_UnclusEnUp_Mom"))           fChainM_["Calo"]->SetBranchAddress("Calo_MET_UnclusEnUp_Mom", &Calo_MET_UnclusEnUp_Mom_, &b_Calo_MET_UnclusEnUp_Mom);
    if (fChainM_["Calo"]->GetBranch("Calo_MET_UnclusEnUp_sumEt"))         fChainM_["Calo"]->SetBranchAddress("Calo_MET_UnclusEnUp_sumEt", &Calo_MET_UnclusEnUp_sumEt_, &b_Calo_MET_UnclusEnUp_sumEt);
    // Set All Branches to Status 0
    fChainM_["Calo"]->SetBranchStatus("*",0);
  }

  // SET GEN MET BRANCHES
  if (fChainM_.count("Gen")>0) {
    if (fChainM_["Gen"]->GetBranch("Gen_MET_Mom"))                        fChainM_["Gen"]->SetBranchAddress("Gen_MET_Mom", &Gen_MET_Mom_, &b_Gen_MET_Mom);
    if (fChainM_["Gen"]->GetBranch("Gen_MET_Inv_Et"))                     fChainM_["Gen"]->SetBranchAddress("Gen_MET_Inv_Et", &Gen_MET_Inv_Et_, &b_Gen_MET_Inv_Et);
    if (fChainM_["Gen"]->GetBranch("Gen_MET_Inv_EtFrac"))                 fChainM_["Gen"]->SetBranchAddress("Gen_MET_Inv_EtFrac", &Gen_MET_Inv_EtFrac_, &b_Gen_MET_Inv_EtFrac);
    if (fChainM_["Gen"]->GetBranch("Gen_MET_Muon_Et"))                    fChainM_["Gen"]->SetBranchAddress("Gen_MET_Muon_Et", &Gen_MET_Muon_Et_, &b_Gen_MET_Muon_Et);
    if (fChainM_["Gen"]->GetBranch("Gen_MET_Muon_EtFrac"))                fChainM_["Gen"]->SetBranchAddress("Gen_MET_Muon_EtFrac", &Gen_MET_Muon_EtFrac_, &b_Gen_MET_Muon_EtFrac);
    if (fChainM_["Gen"]->GetBranch("Gen_MET_EM_Chg_Et"))                  fChainM_["Gen"]->SetBranchAddress("Gen_MET_EM_Chg_Et", &Gen_MET_EM_Chg_Et_, &b_Gen_MET_EM_Chg_Et);
    if (fChainM_["Gen"]->GetBranch("Gen_MET_EM_Chg_EtFrac"))              fChainM_["Gen"]->SetBranchAddress("Gen_MET_EM_Chg_EtFrac", &Gen_MET_EM_Chg_EtFrac_, &b_Gen_MET_EM_Chg_EtFrac);
    if (fChainM_["Gen"]->GetBranch("Gen_MET_EM_Neu_Et"))                  fChainM_["Gen"]->SetBranchAddress("Gen_MET_EM_Neu_Et", &Gen_MET_EM_Neu_Et_, &b_Gen_MET_EM_Neu_Et);
    if (fChainM_["Gen"]->GetBranch("Gen_MET_EM_Neu_EtFrac"))              fChainM_["Gen"]->SetBranchAddress("Gen_MET_EM_Neu_EtFrac", &Gen_MET_EM_Neu_EtFrac_, &b_Gen_MET_EM_Neu_EtFrac);
    if (fChainM_["Gen"]->GetBranch("Gen_MET_Had_Chg_Et"))                 fChainM_["Gen"]->SetBranchAddress("Gen_MET_Had_Chg_Et", &Gen_MET_Had_Chg_Et_, &b_Gen_MET_Had_Chg_Et);
    if (fChainM_["Gen"]->GetBranch("Gen_MET_Had_Chg_EtFrac"))             fChainM_["Gen"]->SetBranchAddress("Gen_MET_Had_Chg_EtFrac", &Gen_MET_Had_Chg_EtFrac_, &b_Gen_MET_Had_Chg_EtFrac);
    if (fChainM_["Gen"]->GetBranch("Gen_MET_Had_Neu_Et"))                 fChainM_["Gen"]->SetBranchAddress("Gen_MET_Had_Neu_Et", &Gen_MET_Had_Neu_Et_, &b_Gen_MET_Had_Neu_Et);
    if (fChainM_["Gen"]->GetBranch("Gen_MET_Had_Neu_EtFrac"))             fChainM_["Gen"]->SetBranchAddress("Gen_MET_Had_Neu_EtFrac", &Gen_MET_Had_Neu_EtFrac_, &b_Gen_MET_Had_Neu_EtFrac);
    // Set All Branches to Status 0
    fChainM_["Gen"]->SetBranchStatus("*",0);
  }

  // SET TYPE 1 CORRECTED MET BRANCHES
  if (fChainM_.count("Type1")>0) {
    if (fChainM_["Type1"]->GetBranch("Type1_MET_NoShift_Mom"))            fChainM_["Type1"]->SetBranchAddress("Type1_MET_NoShift_Mom", &Type1_MET_NoShift_Mom_, &b_Type1_MET_NoShift_Mom);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_NoShift_sumEt"))          fChainM_["Type1"]->SetBranchAddress("Type1_MET_NoShift_sumEt", &Type1_MET_NoShift_sumEt_, &b_Type1_MET_NoShift_sumEt);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_ElectronEnDown_Mom"))     fChainM_["Type1"]->SetBranchAddress("Type1_MET_ElectronEnDown_Mom", &Type1_MET_ElectronEnDown_Mom_, &b_Type1_MET_ElectronEnDown_Mom);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_ElectronEnDown_sumEt"))   fChainM_["Type1"]->SetBranchAddress("Type1_MET_ElectronEnDown_sumEt", &Type1_MET_ElectronEnDown_sumEt_, &b_Type1_MET_ElectronEnDown_sumEt);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_ElectronEnUp_Mom"))       fChainM_["Type1"]->SetBranchAddress("Type1_MET_ElectronEnUp_Mom", &Type1_MET_ElectronEnUp_Mom_, &b_Type1_MET_ElectronEnUp_Mom);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_ElectronEnUp_sumEt"))     fChainM_["Type1"]->SetBranchAddress("Type1_MET_ElectronEnUp_sumEt", &Type1_MET_ElectronEnUp_sumEt_, &b_Type1_MET_ElectronEnUp_sumEt);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_JetEnDown_Mom"))          fChainM_["Type1"]->SetBranchAddress("Type1_MET_JetEnDown_Mom", &Type1_MET_JetEnDown_Mom_, &b_Type1_MET_JetEnDown_Mom);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_JetEnDown_sumEt"))        fChainM_["Type1"]->SetBranchAddress("Type1_MET_JetEnDown_sumEt", &Type1_MET_JetEnDown_sumEt_, &b_Type1_MET_JetEnDown_sumEt);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_JetEnUp_Mom"))            fChainM_["Type1"]->SetBranchAddress("Type1_MET_JetEnUp_Mom", &Type1_MET_JetEnUp_Mom_, &b_Type1_MET_JetEnUp_Mom);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_JetEnUp_sumEt"))          fChainM_["Type1"]->SetBranchAddress("Type1_MET_JetEnUp_sumEt", &Type1_MET_JetEnUp_sumEt_, &b_Type1_MET_JetEnUp_sumEt);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_JetResDown_Mom"))         fChainM_["Type1"]->SetBranchAddress("Type1_MET_JetResDown_Mom", &Type1_MET_JetResDown_Mom_, &b_Type1_MET_JetResDown_Mom);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_JetResDown_sumEt"))       fChainM_["Type1"]->SetBranchAddress("Type1_MET_JetResDown_sumEt", &Type1_MET_JetResDown_sumEt_, &b_Type1_MET_JetResDown_sumEt);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_JetResUp_Mom"))           fChainM_["Type1"]->SetBranchAddress("Type1_MET_JetResUp_Mom", &Type1_MET_JetResUp_Mom_, &b_Type1_MET_JetResUp_Mom);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_JetResUp_sumEt"))         fChainM_["Type1"]->SetBranchAddress("Type1_MET_JetResUp_sumEt", &Type1_MET_JetResUp_sumEt_, &b_Type1_MET_JetResUp_sumEt);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_MuonEnDown_Mom"))         fChainM_["Type1"]->SetBranchAddress("Type1_MET_MuonEnDown_Mom", &Type1_MET_MuonEnDown_Mom_, &b_Type1_MET_MuonEnDown_Mom);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_MuonEnDown_sumEt"))       fChainM_["Type1"]->SetBranchAddress("Type1_MET_MuonEnDown_sumEt", &Type1_MET_MuonEnDown_sumEt_, &b_Type1_MET_MuonEnDown_sumEt);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_MuonEnUp_Mom"))           fChainM_["Type1"]->SetBranchAddress("Type1_MET_MuonEnUp_Mom", &Type1_MET_MuonEnUp_Mom_, &b_Type1_MET_MuonEnUp_Mom);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_MuonEnUp_sumEt"))         fChainM_["Type1"]->SetBranchAddress("Type1_MET_MuonEnUp_sumEt", &Type1_MET_MuonEnUp_sumEt_, &b_Type1_MET_MuonEnUp_sumEt);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_PhotonEnDown_Mom"))       fChainM_["Type1"]->SetBranchAddress("Type1_MET_PhotonEnDown_Mom", &Type1_MET_PhotonEnDown_Mom_, &b_Type1_MET_PhotonEnDown_Mom);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_PhotonEnDown_sumEt"))     fChainM_["Type1"]->SetBranchAddress("Type1_MET_PhotonEnDown_sumEt", &Type1_MET_PhotonEnDown_sumEt_, &b_Type1_MET_PhotonEnDown_sumEt);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_PhotonEnUp_Mom"))         fChainM_["Type1"]->SetBranchAddress("Type1_MET_PhotonEnUp_Mom", &Type1_MET_PhotonEnUp_Mom_, &b_Type1_MET_PhotonEnUp_Mom);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_PhotonEnUp_sumEt"))       fChainM_["Type1"]->SetBranchAddress("Type1_MET_PhotonEnUp_sumEt", &Type1_MET_PhotonEnUp_sumEt_, &b_Type1_MET_PhotonEnUp_sumEt);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_TauEnDown_Mom"))          fChainM_["Type1"]->SetBranchAddress("Type1_MET_TauEnDown_Mom", &Type1_MET_TauEnDown_Mom_, &b_Type1_MET_TauEnDown_Mom);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_TauEnDown_sumEt"))        fChainM_["Type1"]->SetBranchAddress("Type1_MET_TauEnDown_sumEt", &Type1_MET_TauEnDown_sumEt_, &b_Type1_MET_TauEnDown_sumEt);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_TauEnUp_Mom"))            fChainM_["Type1"]->SetBranchAddress("Type1_MET_TauEnUp_Mom", &Type1_MET_TauEnUp_Mom_, &b_Type1_MET_TauEnUp_Mom);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_TauEnUp_sumEt"))          fChainM_["Type1"]->SetBranchAddress("Type1_MET_TauEnUp_sumEt", &Type1_MET_TauEnUp_sumEt_, &b_Type1_MET_TauEnUp_sumEt);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_UnclusEnDown_Mom"))       fChainM_["Type1"]->SetBranchAddress("Type1_MET_UnclusEnDown_Mom", &Type1_MET_UnclusEnDown_Mom_, &b_Type1_MET_UnclusEnDown_Mom);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_UnclusEnDown_sumEt"))     fChainM_["Type1"]->SetBranchAddress("Type1_MET_UnclusEnDown_sumEt", &Type1_MET_UnclusEnDown_sumEt_, &b_Type1_MET_UnclusEnDown_sumEt);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_UnclusEnUp_Mom"))         fChainM_["Type1"]->SetBranchAddress("Type1_MET_UnclusEnUp_Mom", &Type1_MET_UnclusEnUp_Mom_, &b_Type1_MET_UnclusEnUp_Mom);
    if (fChainM_["Type1"]->GetBranch("Type1_MET_UnclusEnUp_sumEt"))       fChainM_["Type1"]->SetBranchAddress("Type1_MET_UnclusEnUp_sumEt", &Type1_MET_UnclusEnUp_sumEt_, &b_Type1_MET_UnclusEnUp_sumEt);
    // Set All Branches to Status 0
    fChainM_["Type1"]->SetBranchStatus("*",0);
  }

  // SET TYPE XY CORRECTED MET BRANCHES
  if (fChainM_.count("TypeXY")>0) {
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_NoShift_Mom"))          fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_NoShift_Mom", &TypeXY_MET_NoShift_Mom_, &b_TypeXY_MET_NoShift_Mom);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_NoShift_sumEt"))        fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_NoShift_sumEt", &TypeXY_MET_NoShift_sumEt_, &b_TypeXY_MET_NoShift_sumEt);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_ElectronEnDown_Mom"))   fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_ElectronEnDown_Mom", &TypeXY_MET_ElectronEnDown_Mom_, &b_TypeXY_MET_ElectronEnDown_Mom);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_ElectronEnDown_sumEt")) fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_ElectronEnDown_sumEt", &TypeXY_MET_ElectronEnDown_sumEt_, &b_TypeXY_MET_ElectronEnDown_sumEt);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_ElectronEnUp_Mom"))     fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_ElectronEnUp_Mom", &TypeXY_MET_ElectronEnUp_Mom_, &b_TypeXY_MET_ElectronEnUp_Mom);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_ElectronEnUp_sumEt"))   fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_ElectronEnUp_sumEt", &TypeXY_MET_ElectronEnUp_sumEt_, &b_TypeXY_MET_ElectronEnUp_sumEt);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_JetEnDown_Mom"))        fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_JetEnDown_Mom", &TypeXY_MET_JetEnDown_Mom_, &b_TypeXY_MET_JetEnDown_Mom);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_JetEnDown_sumEt"))      fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_JetEnDown_sumEt", &TypeXY_MET_JetEnDown_sumEt_, &b_TypeXY_MET_JetEnDown_sumEt);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_JetEnUp_Mom"))          fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_JetEnUp_Mom", &TypeXY_MET_JetEnUp_Mom_, &b_TypeXY_MET_JetEnUp_Mom);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_JetEnUp_sumEt"))        fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_JetEnUp_sumEt", &TypeXY_MET_JetEnUp_sumEt_, &b_TypeXY_MET_JetEnUp_sumEt);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_JetResDown_Mom"))       fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_JetResDown_Mom", &TypeXY_MET_JetResDown_Mom_, &b_TypeXY_MET_JetResDown_Mom);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_JetResDown_sumEt"))     fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_JetResDown_sumEt", &TypeXY_MET_JetResDown_sumEt_, &b_TypeXY_MET_JetResDown_sumEt);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_JetResUp_Mom"))         fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_JetResUp_Mom", &TypeXY_MET_JetResUp_Mom_, &b_TypeXY_MET_JetResUp_Mom);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_JetResUp_sumEt"))       fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_JetResUp_sumEt", &TypeXY_MET_JetResUp_sumEt_, &b_TypeXY_MET_JetResUp_sumEt);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_MuonEnDown_Mom"))       fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_MuonEnDown_Mom", &TypeXY_MET_MuonEnDown_Mom_, &b_TypeXY_MET_MuonEnDown_Mom);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_MuonEnDown_sumEt"))     fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_MuonEnDown_sumEt", &TypeXY_MET_MuonEnDown_sumEt_, &b_TypeXY_MET_MuonEnDown_sumEt);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_MuonEnUp_Mom"))         fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_MuonEnUp_Mom", &TypeXY_MET_MuonEnUp_Mom_, &b_TypeXY_MET_MuonEnUp_Mom);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_MuonEnUp_sumEt"))       fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_MuonEnUp_sumEt", &TypeXY_MET_MuonEnUp_sumEt_, &b_TypeXY_MET_MuonEnUp_sumEt);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_PhotonEnDown_Mom"))     fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_PhotonEnDown_Mom", &TypeXY_MET_PhotonEnDown_Mom_, &b_TypeXY_MET_PhotonEnDown_Mom);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_PhotonEnDown_sumEt"))   fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_PhotonEnDown_sumEt", &TypeXY_MET_PhotonEnDown_sumEt_, &b_TypeXY_MET_PhotonEnDown_sumEt);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_PhotonEnUp_Mom"))       fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_PhotonEnUp_Mom", &TypeXY_MET_PhotonEnUp_Mom_, &b_TypeXY_MET_PhotonEnUp_Mom);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_PhotonEnUp_sumEt"))     fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_PhotonEnUp_sumEt", &TypeXY_MET_PhotonEnUp_sumEt_, &b_TypeXY_MET_PhotonEnUp_sumEt);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_TauEnDown_Mom"))        fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_TauEnDown_Mom", &TypeXY_MET_TauEnDown_Mom_, &b_TypeXY_MET_TauEnDown_Mom);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_TauEnDown_sumEt"))      fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_TauEnDown_sumEt", &TypeXY_MET_TauEnDown_sumEt_, &b_TypeXY_MET_TauEnDown_sumEt);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_TauEnUp_Mom"))          fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_TauEnUp_Mom", &TypeXY_MET_TauEnUp_Mom_, &b_TypeXY_MET_TauEnUp_Mom);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_TauEnUp_sumEt"))        fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_TauEnUp_sumEt", &TypeXY_MET_TauEnUp_sumEt_, &b_TypeXY_MET_TauEnUp_sumEt);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_UnclusEnDown_Mom"))     fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_UnclusEnDown_Mom", &TypeXY_MET_UnclusEnDown_Mom_, &b_TypeXY_MET_UnclusEnDown_Mom);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_UnclusEnDown_sumEt"))   fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_UnclusEnDown_sumEt", &TypeXY_MET_UnclusEnDown_sumEt_, &b_TypeXY_MET_UnclusEnDown_sumEt);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_UnclusEnUp_Mom"))       fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_UnclusEnUp_Mom", &TypeXY_MET_UnclusEnUp_Mom_, &b_TypeXY_MET_UnclusEnUp_Mom);
    if (fChainM_["TypeXY"]->GetBranch("TypeXY_MET_UnclusEnUp_sumEt"))     fChainM_["TypeXY"]->SetBranchAddress("TypeXY_MET_UnclusEnUp_sumEt", &TypeXY_MET_UnclusEnUp_sumEt_, &b_TypeXY_MET_UnclusEnUp_sumEt);
    // Set All Branches to Status 0
    fChainM_["TypeXY"]->SetBranchStatus("*",0);
  }

  // SET TYPE XY CORRECTED MET BRANCHES
  if (fChainM_.count("Filter")>0) {
    if (fChainM_["Filter"]->GetBranch("Flag_BadChargedCandidateFilter"))          fChainM_["Filter"]->SetBranchAddress("Flag_BadChargedCandidateFilter", &Flag_BadChargedCandidateFilter_, &b_Flag_BadChargedCandidateFilter);
    if (fChainM_["Filter"]->GetBranch("Flag_BadChargedCandidateSummer16Filter"))  fChainM_["Filter"]->SetBranchAddress("Flag_BadChargedCandidateSummer16Filter", &Flag_BadChargedCandidateSummer16Filter_, &b_Flag_BadChargedCandidateSummer16Filter);
    if (fChainM_["Filter"]->GetBranch("Flag_BadPFMuonFilter"))                    fChainM_["Filter"]->SetBranchAddress("Flag_BadPFMuonFilter", &Flag_BadPFMuonFilter_, &b_Flag_BadPFMuonFilter);
    if (fChainM_["Filter"]->GetBranch("Flag_BadPFMuonSummer16Filter"))            fChainM_["Filter"]->SetBranchAddress("Flag_BadPFMuonSummer16Filter", &Flag_BadPFMuonSummer16Filter_, &b_Flag_BadPFMuonSummer16Filter);
    if (fChainM_["Filter"]->GetBranch("Flag_CSCTightHalo2015Filter"))             fChainM_["Filter"]->SetBranchAddress("Flag_CSCTightHalo2015Filter", &Flag_CSCTightHalo2015Filter_, &b_Flag_CSCTightHalo2015Filter);
    if (fChainM_["Filter"]->GetBranch("Flag_CSCTightHaloFilter"))                 fChainM_["Filter"]->SetBranchAddress("Flag_CSCTightHaloFilter", &Flag_CSCTightHaloFilter_, &b_Flag_CSCTightHaloFilter);
    if (fChainM_["Filter"]->GetBranch("Flag_CSCTightHaloTrkMuUnvetoFilter"))      fChainM_["Filter"]->SetBranchAddress("Flag_CSCTightHaloTrkMuUnvetoFilter", &Flag_CSCTightHaloTrkMuUnvetoFilter_, &b_Flag_CSCTightHaloTrkMuUnvetoFilter);
    if (fChainM_["Filter"]->GetBranch("Flag_EcalDeadCellBoundaryEnergyFilter"))   fChainM_["Filter"]->SetBranchAddress("Flag_EcalDeadCellBoundaryEnergyFilter", &Flag_EcalDeadCellBoundaryEnergyFilter_, &b_Flag_EcalDeadCellBoundaryEnergyFilter);
    if (fChainM_["Filter"]->GetBranch("Flag_EcalDeadCellTriggerPrimitiveFilter")) fChainM_["Filter"]->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter_, &b_Flag_EcalDeadCellTriggerPrimitiveFilter);
    if (fChainM_["Filter"]->GetBranch("Flag_HBHENoiseFilter"))                    fChainM_["Filter"]->SetBranchAddress("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter_, &b_Flag_HBHENoiseFilter);
    if (fChainM_["Filter"]->GetBranch("Flag_HBHENoiseFilterRun1"))                fChainM_["Filter"]->SetBranchAddress("Flag_HBHENoiseFilterRun1", &Flag_HBHENoiseFilterRun1_, &b_Flag_HBHENoiseFilterRun1);
    if (fChainM_["Filter"]->GetBranch("Flag_HBHENoiseFilterRun2Loose"))           fChainM_["Filter"]->SetBranchAddress("Flag_HBHENoiseFilterRun2Loose", &Flag_HBHENoiseFilterRun2Loose_, &b_Flag_HBHENoiseFilterRun2Loose);
    if (fChainM_["Filter"]->GetBranch("Flag_HBHENoiseFilterRun2Tight"))           fChainM_["Filter"]->SetBranchAddress("Flag_HBHENoiseFilterRun2Tight", &Flag_HBHENoiseFilterRun2Tight_, &b_Flag_HBHENoiseFilterRun2Tight);
    if (fChainM_["Filter"]->GetBranch("Flag_HBHENoiseIsoFilter"))                 fChainM_["Filter"]->SetBranchAddress("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter_, &b_Flag_HBHENoiseIsoFilter);
    if (fChainM_["Filter"]->GetBranch("Flag_HcalStripHaloFilter"))                fChainM_["Filter"]->SetBranchAddress("Flag_HcalStripHaloFilter", &Flag_HcalStripHaloFilter_, &b_Flag_HcalStripHaloFilter);
    if (fChainM_["Filter"]->GetBranch("Flag_badMuons"))                           fChainM_["Filter"]->SetBranchAddress("Flag_badMuons", &Flag_badMuons_, &b_Flag_badMuons);
    if (fChainM_["Filter"]->GetBranch("Flag_badTrackerMuons"))                    fChainM_["Filter"]->SetBranchAddress("Flag_badTrackerMuons", &Flag_badTrackerMuons_, &b_Flag_badTrackerMuons);
    if (fChainM_["Filter"]->GetBranch("Flag_chargedHadronTrackResolutionFilter")) fChainM_["Filter"]->SetBranchAddress("Flag_chargedHadronTrackResolutionFilter", &Flag_chargedHadronTrackResolutionFilter_, &b_Flag_chargedHadronTrackResolutionFilter);
    if (fChainM_["Filter"]->GetBranch("Flag_collisionEventSelectionPA"))          fChainM_["Filter"]->SetBranchAddress("Flag_collisionEventSelectionPA", &Flag_collisionEventSelectionPA_, &b_Flag_collisionEventSelectionPA);
    if (fChainM_["Filter"]->GetBranch("Flag_collisionEventSelectionPA_rejectPU")) fChainM_["Filter"]->SetBranchAddress("Flag_collisionEventSelectionPA_rejectPU", &Flag_collisionEventSelectionPA_rejectPU_, &b_Flag_collisionEventSelectionPA_rejectPU);
    if (fChainM_["Filter"]->GetBranch("Flag_duplicateMuons"))                     fChainM_["Filter"]->SetBranchAddress("Flag_duplicateMuons", &Flag_duplicateMuons_, &b_Flag_duplicateMuons);
    if (fChainM_["Filter"]->GetBranch("Flag_ecalLaserCorrFilter"))                fChainM_["Filter"]->SetBranchAddress("Flag_ecalLaserCorrFilter", &Flag_ecalLaserCorrFilter_, &b_Flag_ecalLaserCorrFilter);
    if (fChainM_["Filter"]->GetBranch("Flag_eeBadScFilter"))                      fChainM_["Filter"]->SetBranchAddress("Flag_eeBadScFilter", &Flag_eeBadScFilter_, &b_Flag_eeBadScFilter);
    if (fChainM_["Filter"]->GetBranch("Flag_globalSuperTightHalo2016Filter"))     fChainM_["Filter"]->SetBranchAddress("Flag_globalSuperTightHalo2016Filter", &Flag_globalSuperTightHalo2016Filter_, &b_Flag_globalSuperTightHalo2016Filter);
    if (fChainM_["Filter"]->GetBranch("Flag_globalTightHalo2016Filter"))          fChainM_["Filter"]->SetBranchAddress("Flag_globalTightHalo2016Filter", &Flag_globalTightHalo2016Filter_, &b_Flag_globalTightHalo2016Filter);
    if (fChainM_["Filter"]->GetBranch("Flag_goodVertices"))                       fChainM_["Filter"]->SetBranchAddress("Flag_goodVertices", &Flag_goodVertices_, &b_Flag_goodVertices);
    if (fChainM_["Filter"]->GetBranch("Flag_hcalLaserEventFilter"))               fChainM_["Filter"]->SetBranchAddress("Flag_hcalLaserEventFilter", &Flag_hcalLaserEventFilter_, &b_Flag_hcalLaserEventFilter);
    if (fChainM_["Filter"]->GetBranch("Flag_muonBadTrackFilter"))                 fChainM_["Filter"]->SetBranchAddress("Flag_muonBadTrackFilter", &Flag_muonBadTrackFilter_, &b_Flag_muonBadTrackFilter);
    if (fChainM_["Filter"]->GetBranch("Flag_noBadMuons"))                         fChainM_["Filter"]->SetBranchAddress("Flag_noBadMuons", &Flag_noBadMuons_, &b_Flag_noBadMuons);
    if (fChainM_["Filter"]->GetBranch("Flag_trkPOGFilters"))                      fChainM_["Filter"]->SetBranchAddress("Flag_trkPOGFilters", &Flag_trkPOGFilters_, &b_Flag_trkPOGFilters);
    if (fChainM_["Filter"]->GetBranch("Flag_trkPOG_logErrorTooManyClusters"))     fChainM_["Filter"]->SetBranchAddress("Flag_trkPOG_logErrorTooManyClusters", &Flag_trkPOG_logErrorTooManyClusters_, &b_Flag_trkPOG_logErrorTooManyClusters);
    if (fChainM_["Filter"]->GetBranch("Flag_trkPOG_manystripclus53X"))            fChainM_["Filter"]->SetBranchAddress("Flag_trkPOG_manystripclus53X", &Flag_trkPOG_manystripclus53X_, &b_Flag_trkPOG_manystripclus53X);
    if (fChainM_["Filter"]->GetBranch("Flag_trkPOG_toomanystripclus53X"))         fChainM_["Filter"]->SetBranchAddress("Flag_trkPOG_toomanystripclus53X", &Flag_trkPOG_toomanystripclus53X_, &b_Flag_trkPOG_toomanystripclus53X);
    // Set All Branches to Status 0
    fChainM_["Filter"]->SetBranchStatus("*",0);
  }
}

void HiMETTree::Clear(void)
{
  if (fChainM_.size()==0) return;

  // CLEAR EVENT INFO
  Event_Run_    = 0;
  Event_Lumi_   = 0;
  Event_Bx_     = 0;
  Event_Number_ = 0;
   
  // CLEAR RECO MET VARIABLES
  if (Reco_MET_Mom_)  *Reco_MET_Mom_ = TVector2();
  if (Reco_MET_SigM_) *Reco_MET_SigM_ = TMatrixD();
  Reco_MET_Sig_    = -1.;
  Reco_MET_sumEt_  = -1.;
  Reco_MET_mEtSig_ = -1.;
   
  // CLEAR PF MET VARIABLES
  if (PF_MET_Mom_) *PF_MET_Mom_ = TVector2();
  PF_MET_Muon_Et_              = -1.;
  PF_MET_Muon_EtFrac_          = -1.;
  PF_MET_EM_Chg_Et_            = -1.;
  PF_MET_EM_Chg_EtFrac_        = -1.;
  PF_MET_EM_Neu_Et_            = -1.;
  PF_MET_EM_Neu_EtFrac_        = -1.;
  PF_MET_EM_HF_Et_             = -1.;
  PF_MET_EM_HF_EtFrac_         = -1.;
  PF_MET_Had_Chg_Et_           = -1.;
  PF_MET_Had_Chg_EtFrac_       = -1.;
  PF_MET_Had_Neu_Et_           = -1.;
  PF_MET_Had_Neu_EtFrac_       = -1.;
  PF_MET_Had_HF_Et_            = -1.;
  PF_MET_Had_HF_EtFrac_        = -1.;
  PF_MET_NoShift_sumEt_        = -1.;
  PF_MET_ElectronEnDown_sumEt_ = -1.;
  PF_MET_ElectronEnUp_sumEt_   = -1.;
  PF_MET_JetEnDown_sumEt_      = -1.;
  PF_MET_JetEnUp_sumEt_        = -1.;
  PF_MET_JetResDown_sumEt_     = -1.;
  PF_MET_JetResUp_sumEt_       = -1.;
  PF_MET_MuonEnDown_sumEt_     = -1.;
  PF_MET_MuonEnUp_sumEt_       = -1.;
  PF_MET_PhotonEnDown_sumEt_   = -1.;
  PF_MET_PhotonEnUp_sumEt_     = -1.;
  PF_MET_TauEnDown_sumEt_      = -1.;
  PF_MET_TauEnUp_sumEt_        = -1.;
  PF_MET_UnclusEnDown_sumEt_   = -1.;
  PF_MET_UnclusEnUp_sumEt_     = -1.;
  if (PF_MET_NoShift_Mom_)        *PF_MET_NoShift_Mom_ = TVector2();
  if (PF_MET_ElectronEnDown_Mom_) *PF_MET_ElectronEnDown_Mom_ = TVector2();
  if (PF_MET_ElectronEnUp_Mom_)   *PF_MET_ElectronEnUp_Mom_ = TVector2();
  if (PF_MET_JetEnDown_Mom_)      *PF_MET_JetEnDown_Mom_ = TVector2();
  if (PF_MET_JetEnUp_Mom_)        *PF_MET_JetEnUp_Mom_ = TVector2();
  if (PF_MET_JetResDown_Mom_)     *PF_MET_JetResDown_Mom_ = TVector2();
  if (PF_MET_JetResUp_Mom_)       *PF_MET_JetResUp_Mom_ = TVector2();
  if (PF_MET_MuonEnDown_Mom_)     *PF_MET_MuonEnDown_Mom_ = TVector2();
  if (PF_MET_MuonEnUp_Mom_)       *PF_MET_MuonEnUp_Mom_ = TVector2();
  if (PF_MET_PhotonEnDown_Mom_)   *PF_MET_PhotonEnDown_Mom_ = TVector2();
  if (PF_MET_PhotonEnUp_Mom_)     *PF_MET_PhotonEnUp_Mom_ = TVector2();
  if (PF_MET_TauEnDown_Mom_)      *PF_MET_TauEnDown_Mom_ = TVector2();
  if (PF_MET_TauEnUp_Mom_)        *PF_MET_TauEnUp_Mom_ = TVector2();
  if (PF_MET_UnclusEnDown_Mom_)   *PF_MET_UnclusEnDown_Mom_ = TVector2();
  if (PF_MET_UnclusEnUp_Mom_)     *PF_MET_UnclusEnUp_Mom_ = TVector2();
   
  // CLEAR CALO MET VARIABLES
  if (Calo_MET_Mom_) *Calo_MET_Mom_ = TVector2();
  Calo_MET_Sig_                  = -1.;
  Calo_MET_mHF_Et_               = -1.;
  Calo_MET_mHF_Phi_              = -1.;
  Calo_MET_mHF_sumEt_            = -1.;
  Calo_MET_pHF_Et_               = -1.;
  Calo_MET_pHF_Phi_              = -1.;
  Calo_MET_pHF_sumEt_            = -1.;
  Calo_MET_EM_EtFrac_            = -1.;
  Calo_MET_EM_EB_Et_             = -1.;
  Calo_MET_EM_EE_Et_             = -1.;
  Calo_MET_EM_HF_Et_             = -1.;
  Calo_MET_EM_Tow_maxEt_         = -1.;
  Calo_MET_Had_EtFrac_           = -1.;
  Calo_MET_Had_HB_Et_            = -1.;
  Calo_MET_Had_HE_Et_            = -1.;
  Calo_MET_Had_HF_Et_            = -1.;
  Calo_MET_Had_HO_Et_            = -1.;
  Calo_MET_Had_Tow_maxEt_        = -1.;
  Calo_MET_NoShift_sumEt_        = -1.;
  Calo_MET_ElectronEnDown_sumEt_ = -1.;
  Calo_MET_ElectronEnUp_sumEt_   = -1.;
  Calo_MET_JetEnDown_sumEt_      = -1.;
  Calo_MET_JetEnUp_sumEt_        = -1.;
  Calo_MET_JetResDown_sumEt_     = -1.;
  Calo_MET_JetResUp_sumEt_       = -1.;
  Calo_MET_MuonEnDown_sumEt_     = -1.;
  Calo_MET_MuonEnUp_sumEt_       = -1.;
  Calo_MET_PhotonEnDown_sumEt_   = -1.;
  Calo_MET_PhotonEnUp_sumEt_     = -1.;
  Calo_MET_TauEnDown_sumEt_      = -1.;
  Calo_MET_TauEnUp_sumEt_        = -1.;
  Calo_MET_UnclusEnDown_sumEt_   = -1.;
  Calo_MET_UnclusEnUp_sumEt_     = -1.;
  if (Calo_MET_NoShift_Mom_)        *Calo_MET_NoShift_Mom_ = TVector2();
  if (Calo_MET_ElectronEnDown_Mom_) *Calo_MET_ElectronEnDown_Mom_ = TVector2();
  if (Calo_MET_ElectronEnUp_Mom_)   *Calo_MET_ElectronEnUp_Mom_ = TVector2();
  if (Calo_MET_JetEnDown_Mom_)      *Calo_MET_JetEnDown_Mom_ = TVector2();
  if (Calo_MET_JetEnUp_Mom_)        *Calo_MET_JetEnUp_Mom_ = TVector2();
  if (Calo_MET_JetResDown_Mom_)     *Calo_MET_JetResDown_Mom_ = TVector2();
  if (Calo_MET_JetResUp_Mom_)       *Calo_MET_JetResUp_Mom_ = TVector2();
  if (Calo_MET_MuonEnDown_Mom_)     *Calo_MET_MuonEnDown_Mom_ = TVector2();
  if (Calo_MET_MuonEnUp_Mom_)       *Calo_MET_MuonEnUp_Mom_ = TVector2();
  if (Calo_MET_PhotonEnDown_Mom_)   *Calo_MET_PhotonEnDown_Mom_ = TVector2();
  if (Calo_MET_PhotonEnUp_Mom_)     *Calo_MET_PhotonEnUp_Mom_ = TVector2();
  if (Calo_MET_TauEnDown_Mom_)      *Calo_MET_TauEnDown_Mom_ = TVector2();
  if (Calo_MET_TauEnUp_Mom_)        *Calo_MET_TauEnUp_Mom_ = TVector2();
  if (Calo_MET_UnclusEnDown_Mom_)   *Calo_MET_UnclusEnDown_Mom_ = TVector2();
  if (Calo_MET_UnclusEnUp_Mom_)     *Calo_MET_UnclusEnUp_Mom_ = TVector2();
   
  // CLEAR GEN MET VARIABLES
  if (Gen_MET_Mom_) *Gen_MET_Mom_ = TVector2();
  Gen_MET_Inv_Et_         = -1.;
  Gen_MET_Inv_EtFrac_     = -1.;
  Gen_MET_Muon_Et_        = -1.;
  Gen_MET_Muon_EtFrac_    = -1.;
  Gen_MET_EM_Chg_Et_      = -1.;
  Gen_MET_EM_Chg_EtFrac_  = -1.;
  Gen_MET_EM_Neu_Et_      = -1.;
  Gen_MET_EM_Neu_EtFrac_  = -1.;
  Gen_MET_Had_Chg_Et_     = -1.;
  Gen_MET_Had_Chg_EtFrac_ = -1.;
  Gen_MET_Had_Neu_Et_     = -1.;
  Gen_MET_Had_Neu_EtFrac_ = -1.;
   
  // CLEAR TYPE 1 CORRECTED MET VARIABLES
  Type1_MET_NoShift_sumEt_        = -1.;
  Type1_MET_ElectronEnDown_sumEt_ = -1.;
  Type1_MET_ElectronEnUp_sumEt_   = -1.;
  Type1_MET_JetEnDown_sumEt_      = -1.;
  Type1_MET_JetEnUp_sumEt_        = -1.;
  Type1_MET_JetResDown_sumEt_     = -1.;
  Type1_MET_JetResUp_sumEt_       = -1.;
  Type1_MET_MuonEnDown_sumEt_     = -1.;
  Type1_MET_MuonEnUp_sumEt_       = -1.;
  Type1_MET_PhotonEnDown_sumEt_   = -1.;
  Type1_MET_PhotonEnUp_sumEt_     = -1.;
  Type1_MET_TauEnDown_sumEt_      = -1.;
  Type1_MET_TauEnUp_sumEt_        = -1.;
  Type1_MET_UnclusEnDown_sumEt_   = -1.;
  Type1_MET_UnclusEnUp_sumEt_     = -1.;
  if (Type1_MET_NoShift_Mom_)        *Type1_MET_NoShift_Mom_ = TVector2();
  if (Type1_MET_ElectronEnDown_Mom_) *Type1_MET_ElectronEnDown_Mom_ = TVector2();
  if (Type1_MET_ElectronEnUp_Mom_)   *Type1_MET_ElectronEnUp_Mom_ = TVector2();
  if (Type1_MET_JetEnDown_Mom_)      *Type1_MET_JetEnDown_Mom_ = TVector2();
  if (Type1_MET_JetEnUp_Mom_)        *Type1_MET_JetEnUp_Mom_ = TVector2();
  if (Type1_MET_JetResDown_Mom_)     *Type1_MET_JetResDown_Mom_ = TVector2();
  if (Type1_MET_JetResUp_Mom_)       *Type1_MET_JetResUp_Mom_ = TVector2();
  if (Type1_MET_MuonEnDown_Mom_)     *Type1_MET_MuonEnDown_Mom_ = TVector2();
  if (Type1_MET_MuonEnUp_Mom_)       *Type1_MET_MuonEnUp_Mom_ = TVector2();
  if (Type1_MET_PhotonEnDown_Mom_)   *Type1_MET_PhotonEnDown_Mom_ = TVector2();
  if (Type1_MET_PhotonEnUp_Mom_)     *Type1_MET_PhotonEnUp_Mom_ = TVector2();
  if (Type1_MET_TauEnDown_Mom_)      *Type1_MET_TauEnDown_Mom_ = TVector2();
  if (Type1_MET_TauEnUp_Mom_)        *Type1_MET_TauEnUp_Mom_ = TVector2();
  if (Type1_MET_UnclusEnDown_Mom_)   *Type1_MET_UnclusEnDown_Mom_ = TVector2();
  if (Type1_MET_UnclusEnUp_Mom_)     *Type1_MET_UnclusEnUp_Mom_ = TVector2();
   
  // CLEAR TYPE XY CORRECTED MET VARIABLES
  TypeXY_MET_NoShift_sumEt_        = -1.;
  TypeXY_MET_ElectronEnDown_sumEt_ = -1.;
  TypeXY_MET_ElectronEnUp_sumEt_   = -1.;
  TypeXY_MET_JetEnDown_sumEt_      = -1.;
  TypeXY_MET_JetEnUp_sumEt_        = -1.;
  TypeXY_MET_JetResDown_sumEt_     = -1.;
  TypeXY_MET_JetResUp_sumEt_       = -1.;
  TypeXY_MET_MuonEnDown_sumEt_     = -1.;
  TypeXY_MET_MuonEnUp_sumEt_       = -1.;
  TypeXY_MET_PhotonEnDown_sumEt_   = -1.;
  TypeXY_MET_PhotonEnUp_sumEt_     = -1.;
  TypeXY_MET_TauEnDown_sumEt_      = -1.;
  TypeXY_MET_TauEnUp_sumEt_        = -1.;
  TypeXY_MET_UnclusEnDown_sumEt_   = -1.;
  TypeXY_MET_UnclusEnUp_sumEt_     = -1.;
  if (TypeXY_MET_NoShift_Mom_)        *TypeXY_MET_NoShift_Mom_ = TVector2();
  if (TypeXY_MET_ElectronEnDown_Mom_) *TypeXY_MET_ElectronEnDown_Mom_ = TVector2();
  if (TypeXY_MET_ElectronEnUp_Mom_)   *TypeXY_MET_ElectronEnUp_Mom_ = TVector2();
  if (TypeXY_MET_JetEnDown_Mom_)      *TypeXY_MET_JetEnDown_Mom_ = TVector2();
  if (TypeXY_MET_JetEnUp_Mom_)        *TypeXY_MET_JetEnUp_Mom_ = TVector2();
  if (TypeXY_MET_JetResDown_Mom_)     *TypeXY_MET_JetResDown_Mom_ = TVector2();
  if (TypeXY_MET_JetResUp_Mom_)       *TypeXY_MET_JetResUp_Mom_ = TVector2();
  if (TypeXY_MET_MuonEnDown_Mom_)     *TypeXY_MET_MuonEnDown_Mom_ = TVector2();
  if (TypeXY_MET_MuonEnUp_Mom_)       *TypeXY_MET_MuonEnUp_Mom_ = TVector2();
  if (TypeXY_MET_PhotonEnDown_Mom_)   *TypeXY_MET_PhotonEnDown_Mom_ = TVector2();
  if (TypeXY_MET_PhotonEnUp_Mom_)     *TypeXY_MET_PhotonEnUp_Mom_ = TVector2();
  if (TypeXY_MET_TauEnDown_Mom_)      *TypeXY_MET_TauEnDown_Mom_ = TVector2();
  if (TypeXY_MET_TauEnUp_Mom_)        *TypeXY_MET_TauEnUp_Mom_ = TVector2();
  if (TypeXY_MET_UnclusEnDown_Mom_)   *TypeXY_MET_UnclusEnDown_Mom_ = TVector2();
  if (TypeXY_MET_UnclusEnUp_Mom_)     *TypeXY_MET_UnclusEnUp_Mom_ = TVector2();
   
  // CLEAR MET FILTERS
  Flag_BadChargedCandidateFilter_          = 0;
  Flag_BadChargedCandidateSummer16Filter_  = 0;
  Flag_BadPFMuonFilter_                    = 0;
  Flag_BadPFMuonSummer16Filter_            = 0;
  Flag_CSCTightHalo2015Filter_             = 0;
  Flag_CSCTightHaloFilter_                 = 0;
  Flag_CSCTightHaloTrkMuUnvetoFilter_      = 0;
  Flag_EcalDeadCellBoundaryEnergyFilter_   = 0;
  Flag_EcalDeadCellTriggerPrimitiveFilter_ = 0;
  Flag_HBHENoiseFilter_                    = 0;
  Flag_HBHENoiseFilterRun1_                = 0;
  Flag_HBHENoiseFilterRun2Loose_           = 0;
  Flag_HBHENoiseFilterRun2Tight_           = 0;
  Flag_HBHENoiseIsoFilter_                 = 0;
  Flag_HcalStripHaloFilter_                = 0;
  Flag_badMuons_                           = 0;
  Flag_badTrackerMuons_                    = 0;
  Flag_chargedHadronTrackResolutionFilter_ = 0;
  Flag_collisionEventSelectionPA_          = 0;
  Flag_collisionEventSelectionPA_rejectPU_ = 0;
  Flag_duplicateMuons_                     = 0;
  Flag_ecalLaserCorrFilter_                = 0;
  Flag_eeBadScFilter_                      = 0;
  Flag_globalSuperTightHalo2016Filter_     = 0;
  Flag_globalTightHalo2016Filter_          = 0;
  Flag_goodVertices_                       = 0;
  Flag_hcalLaserEventFilter_               = 0;
  Flag_muonBadTrackFilter_                 = 0;
  Flag_noBadMuons_                         = 0;
  Flag_trkPOGFilters_                      = 0;
  Flag_trkPOG_logErrorTooManyClusters_     = 0;
  Flag_trkPOG_manystripclus53X_            = 0;
  Flag_trkPOG_toomanystripclus53X_         = 0;
}

#endif
