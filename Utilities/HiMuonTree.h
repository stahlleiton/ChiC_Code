#ifndef HiMuonTree_h
#define HiMuonTree_h

// Header file for ROOT classes
#include <TROOT.h>
#include <TChain.h>
#include <TInterpreter.h>
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

class HiMuonTree {

public :

  HiMuonTree();
  virtual ~HiMuonTree();
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
  std::vector<bool>    Event_Trig_Fired()                 { SetBranch("Event_Trig_Fired");                 return GET(Event_Trig_Fired_);                 }
  std::vector<int>     Event_Trig_Presc()                 { SetBranch("Event_Trig_Presc");                 return GET(Event_Trig_Presc_);                 }

  // RECO MUON VARIABLES
  UChar_t              Reco_Muon_N()                      { SetBranch("Reco_Muon_N");                      return Reco_Muon_N_;                           }
  VTLorentzVector      Reco_Muon_Mom()                    { SetBranch("Reco_Muon_Mom");                    return EXTRACTLV("Reco_Muon_Mom");             }
  std::vector<char>    Reco_Muon_Charge()                 { SetBranch("Reco_Muon_Charge");                 return GET(Reco_Muon_Charge_);                 }
  std::vector<char>    Reco_Muon_Gen_Idx()                { SetBranch("Reco_Muon_Gen_Idx");                return GET(Reco_Muon_Gen_Idx_);                }
  std::vector<char>    Reco_Muon_PF_Idx()                 { SetBranch("Reco_Muon_PF_Idx");                 return GET(Reco_Muon_PF_Idx_);                 }
  UCharVecVec          Pat_Muon_Trig()                    { SetBranch("Pat_Muon_Trig");                    return GET(Pat_Muon_Trig_) ;                   }
  std::vector<float>   Pat_Muon_dB()                      { SetBranch("Pat_Muon_dB");                      return GET(Pat_Muon_dB_);                      }
  std::vector<float>   Pat_Muon_dBErr()                   { SetBranch("Pat_Muon_dBErr");                   return GET(Pat_Muon_dBErr_ );                  }
  std::vector<bool>    Reco_Muon_isPF()                   { SetBranch("Reco_Muon_isPF");                   return GET(Reco_Muon_isPF_);                   }
  std::vector<bool>    Reco_Muon_isGlobal()               { SetBranch("Reco_Muon_isGlobal");               return GET(Reco_Muon_isGlobal_);               }
  std::vector<bool>    Reco_Muon_isTracker()              { SetBranch("Reco_Muon_isTracker");              return GET(Reco_Muon_isTracker_);              }
  std::vector<bool>    Reco_Muon_isStandAlone()           { SetBranch("Reco_Muon_isStandAlone");           return GET(Reco_Muon_isStandAlone_);           }
  std::vector<bool>    Reco_Muon_isLoose()                { SetBranch("Reco_Muon_isLoose");                return GET(Reco_Muon_isLoose_);                }
  std::vector<bool>    Reco_Muon_isMedium()               { SetBranch("Reco_Muon_isMedium");               return GET(Reco_Muon_isMedium_);               }
  std::vector<bool>    Reco_Muon_isHighPt()               { SetBranch("Reco_Muon_isHighPt");               return GET(Reco_Muon_isHighPt_);               }
  std::vector<bool>    Reco_Muon_isSoft()                 { SetBranch("Reco_Muon_isSoft");                 return GET(Reco_Muon_isSoft_);                 }
  std::vector<bool>    Reco_Muon_isTight()                { SetBranch("Reco_Muon_isTight");                return GET(Reco_Muon_isTight_);                }
  std::vector<bool>    Reco_Muon_isArbitrated()           { SetBranch("Reco_Muon_isArbitrated");           return GET(Reco_Muon_isArbitrated_);           }
  std::vector<bool>    Reco_Muon_TrackerArbitrated()      { SetBranch("Reco_Muon_TrackerArbitrated");      return GET(Reco_Muon_TrackerArbitrated_);      }
  std::vector<bool>    Reco_Muon_GlobalPromptTight()      { SetBranch("Reco_Muon_GlobalPromptTight");      return GET(Reco_Muon_GlobalPromptTight_);      }
  std::vector<bool>    Reco_Muon_TMLastStationLoose()     { SetBranch("Reco_Muon_TMLastStationLoose");     return GET(Reco_Muon_TMLastStationLoose_);     }
  std::vector<bool>    Reco_Muon_TMLastStationTight()     { SetBranch("Reco_Muon_TMLastStationTight");     return GET(Reco_Muon_TMLastStationTight_);     }
  std::vector<bool>    Reco_Muon_TM2DCompatibilityLoose() { SetBranch("Reco_Muon_TM2DCompatibilityLoose"); return GET(Reco_Muon_TM2DCompatibilityLoose_); }
  std::vector<bool>    Reco_Muon_TM2DCompatibilityTight() { SetBranch("Reco_Muon_TM2DCompatibilityTight"); return GET(Reco_Muon_TM2DCompatibilityTight_); }
  std::vector<bool>    Reco_Muon_TMOneStationLoose()      { SetBranch("Reco_Muon_TMOneStationLoose");      return GET(Reco_Muon_TMOneStationLoose_);      }
  std::vector<bool>    Reco_Muon_TMOneStationTight()      { SetBranch("Reco_Muon_TMOneStationTight");      return GET(Reco_Muon_TMOneStationTight_);      }
  std::vector<bool>    Reco_Muon_GMTkChiCompatibility()   { SetBranch("Reco_Muon_GMTkChiCompatibility");   return GET(Reco_Muon_GMTkChiCompatibility_);   }
  std::vector<bool>    Reco_Muon_GMStaChiCompatibility()  { SetBranch("Reco_Muon_GMStaChiCompatibility");  return GET(Reco_Muon_GMStaChiCompatibility_);  }
  std::vector<bool>    Reco_Muon_GMTkKinkTight()          { SetBranch("Reco_Muon_GMTkKinkTight");          return GET(Reco_Muon_GMTkKinkTight_);          }
  std::vector<bool>    Reco_Muon_TMLastStationAngLoose()  { SetBranch("Reco_Muon_TMLastStationAngLoose");  return GET(Reco_Muon_TMLastStationAngLoose_);  }
  std::vector<bool>    Reco_Muon_TMLastStationAngTight()  { SetBranch("Reco_Muon_TMLastStationAngTight");  return GET(Reco_Muon_TMLastStationAngTight_);  }
  std::vector<bool>    Reco_Muon_TMOneStationAngLoose()   { SetBranch("Reco_Muon_TMOneStationAngLoose");   return GET(Reco_Muon_TMOneStationAngLoose_);   }
  std::vector<bool>    Reco_Muon_TMOneStationAngTight()   { SetBranch("Reco_Muon_TMOneStationAngTight");   return GET(Reco_Muon_TMOneStationAngTight_);   }
  std::vector<short>   Reco_Muon_MatchedStations()        { SetBranch("Reco_Muon_MatchedStations");        return GET(Reco_Muon_MatchedStations_);        }
  std::vector<short>   Reco_Muon_Matches()                { SetBranch("Reco_Muon_Matches");                return GET(Reco_Muon_Matches_);                }
  std::vector<float>   Reco_Muon_SegmentComp()            { SetBranch("Reco_Muon_SegmentComp");            return GET(Reco_Muon_SegmentComp_);            }
  std::vector<float>   Reco_Muon_Chi2Pos()                { SetBranch("Reco_Muon_Chi2Pos");                return GET(Reco_Muon_Chi2Pos_);                }
  std::vector<float>   Reco_Muon_TrkKink()                { SetBranch("Reco_Muon_TrkKink");                return GET(Reco_Muon_TrkKink_);                }
  VTLorentzVector      Reco_Muon_InTrk_Mom()              { SetBranch("Reco_Muon_InTrk_Mom");              return EXTRACTLV("Reco_Muon_InTrk_Mom");       }
  std::vector<float>   Reco_Muon_InTrk_PtErr()            { SetBranch("Reco_Muon_InTrk_PtErr");            return GET(Reco_Muon_InTrk_PtErr_);            }
  std::vector<bool>    Reco_Muon_InTrk_isHighPurity()     { SetBranch("Reco_Muon_InTrk_isHighPurity");     return GET(Reco_Muon_InTrk_isHighPurity_);     }
  std::vector<short>   Reco_Muon_InTrk_ValidHits()        { SetBranch("Reco_Muon_InTrk_ValidHits");        return GET(Reco_Muon_InTrk_ValidHits_);        }
  std::vector<short>   Reco_Muon_InTrk_LostHits()         { SetBranch("Reco_Muon_InTrk_LostHits");         return GET(Reco_Muon_InTrk_LostHits_);         }
  std::vector<short>   Reco_Muon_InTrk_ValidPixHits()     { SetBranch("Reco_Muon_InTrk_ValidPixHits");     return GET(Reco_Muon_InTrk_ValidPixHits_);     }
  std::vector<short>   Reco_Muon_InTrk_TrkLayers()        { SetBranch("Reco_Muon_InTrk_TrkLayers");        return GET(Reco_Muon_InTrk_TrkLayers_);        }
  std::vector<short>   Reco_Muon_InTrk_PixLayers()        { SetBranch("Reco_Muon_InTrk_PixLayers");        return GET(Reco_Muon_InTrk_PixLayers_);        }
  std::vector<float>   Reco_Muon_InTrk_dXY()              { SetBranch("Reco_Muon_InTrk_dXY");              return GET(Reco_Muon_InTrk_dXY_);              }
  std::vector<float>   Reco_Muon_InTrk_dXYErr()           { SetBranch("Reco_Muon_InTrk_dXYErr");           return GET(Reco_Muon_InTrk_dXYErr_);           }
  std::vector<float>   Reco_Muon_InTrk_dZ()               { SetBranch("Reco_Muon_InTrk_dZ");               return GET(Reco_Muon_InTrk_dZ_);               }
  std::vector<float>   Reco_Muon_InTrk_dZErr()            { SetBranch("Reco_Muon_InTrk_dZErr");            return GET(Reco_Muon_InTrk_dZErr_);            }
  std::vector<float>   Reco_Muon_InTrk_ValFrac()          { SetBranch("Reco_Muon_InTrk_ValFrac");          return GET(Reco_Muon_InTrk_ValFrac_);          }
  std::vector<float>   Reco_Muon_InTrk_NormChi2()         { SetBranch("Reco_Muon_InTrk_NormChi2");         return GET(Reco_Muon_InTrk_NormChi2_);         }
  VTLorentzVector      Reco_Muon_GlbTrk_Mom()             { SetBranch("Reco_Muon_GlbTrk_Mom");             return EXTRACTLV("Reco_Muon_GlbTrk_Mom");      }
  std::vector<float>   Reco_Muon_GlbTrk_PtErr()           { SetBranch("Reco_Muon_GlbTrk_PtErr");           return GET(Reco_Muon_GlbTrk_PtErr_);           }
  std::vector<short>   Reco_Muon_GlbTrk_ValidMuonHits()   { SetBranch("Reco_Muon_GlbTrk_ValidMuonHits");   return GET(Reco_Muon_GlbTrk_ValidMuonHits_);   }
  std::vector<float>   Reco_Muon_GlbTrk_NormChi2()        { SetBranch("Reco_Muon_GlbTrk_NormChi2");        return GET(Reco_Muon_GlbTrk_NormChi2_);        }
  std::vector<char>    Reco_Muon_BestTrk_Type()           { SetBranch("Reco_Muon_BestTrk_Type");           return GET(Reco_Muon_BestTrk_Type_);           }
  VTLorentzVector      Reco_Muon_BestTrk_Mom()            { SetBranch("Reco_Muon_BestTrk_Mom");            return EXTRACTLV("Reco_Muon_BestTrk_Mom");     }
  VTVector3            Reco_Muon_BestTrk_Vertex()         { SetBranch("Reco_Muon_BestTrk_Vertex");         return EXTRACTV3("Reco_Muon_BestTrk_Vertex");  }
  std::vector<float>   Reco_Muon_BestTrk_PtErr()          { SetBranch("Reco_Muon_BestTrk_PtErr");          return GET(Reco_Muon_BestTrk_PtErr_);          }
  std::vector<float>   Reco_Muon_BestTrk_dXY()            { SetBranch("Reco_Muon_BestTrk_dXY");            return GET(Reco_Muon_BestTrk_dXY_);            }
  std::vector<float>   Reco_Muon_BestTrk_dXYErr()         { SetBranch("Reco_Muon_BestTrk_dXYErr");         return GET(Reco_Muon_BestTrk_dXYErr_);         }
  std::vector<float>   Reco_Muon_BestTrk_dZ()             { SetBranch("Reco_Muon_BestTrk_dZ");             return GET(Reco_Muon_BestTrk_dZ_);             }
  std::vector<float>   Reco_Muon_BestTrk_dZErr()          { SetBranch("Reco_Muon_BestTrk_dZErr");          return GET(Reco_Muon_BestTrk_dZErr_);          }
  std::vector<float>   Reco_Muon_IsoPFR03()               { SetBranch("Reco_Muon_IsoPFR03");               return GET(Reco_Muon_IsoPFR03_);               }
  std::vector<float>   Reco_Muon_IsoPFR03NoPUCorr()       { SetBranch("Reco_Muon_IsoPFR03NoPUCorr");       return GET(Reco_Muon_IsoPFR03NoPUCorr_);       }
  std::vector<float>   Reco_Muon_IsoPFR04()               { SetBranch("Reco_Muon_IsoPFR04");               return GET(Reco_Muon_IsoPFR04_);               }
  std::vector<float>   Reco_Muon_IsoPFR04NoPUCorr()       { SetBranch("Reco_Muon_IsoPFR04NoPUCorr");       return GET(Reco_Muon_IsoPFR04NoPUCorr_);       }
  std::vector<float>   Reco_Muon_EM_Chg_sumR03Pt()        { SetBranch("Reco_Muon_EM_Chg_sumR03Pt");        return GET(Reco_Muon_EM_Chg_sumR03Pt_);        }
  std::vector<float>   Reco_Muon_EM_Chg_sumR04Pt()        { SetBranch("Reco_Muon_EM_Chg_sumR04Pt");        return GET(Reco_Muon_EM_Chg_sumR04Pt_);        }
  std::vector<float>   Reco_Muon_EM_Neu_sumR03Et()        { SetBranch("Reco_Muon_EM_Neu_sumR03Et");        return GET(Reco_Muon_EM_Neu_sumR03Et_);        }
  std::vector<float>   Reco_Muon_EM_Neu_sumR04Et()        { SetBranch("Reco_Muon_EM_Neu_sumR04Et");        return GET(Reco_Muon_EM_Neu_sumR04Et_);        }
  std::vector<float>   Reco_Muon_Had_Chg_sumR03Pt()       { SetBranch("Reco_Muon_Had_Chg_sumR03Pt");       return GET(Reco_Muon_Had_Chg_sumR03Pt_);       }
  std::vector<float>   Reco_Muon_Had_Chg_sumR04Pt()       { SetBranch("Reco_Muon_Had_Chg_sumR04Pt");       return GET(Reco_Muon_Had_Chg_sumR04Pt_);       }
  std::vector<float>   Reco_Muon_Had_Neu_sumR03Et()       { SetBranch("Reco_Muon_Had_Neu_sumR03Et");       return GET(Reco_Muon_Had_Neu_sumR03Et_);       }
  std::vector<float>   Reco_Muon_Had_Neu_sumR04Et()       { SetBranch("Reco_Muon_Had_Neu_sumR04Et");       return GET(Reco_Muon_Had_Neu_sumR04Et_);       }
  std::vector<float>   Reco_Muon_Had_PU_sumR03Pt()        { SetBranch("Reco_Muon_Had_PU_sumR03Pt");        return GET(Reco_Muon_Had_PU_sumR03Pt_);        }
  std::vector<float>   Reco_Muon_Had_PU_sumR04Pt()        { SetBranch("Reco_Muon_Had_PU_sumR04Pt");        return GET(Reco_Muon_Had_PU_sumR04Pt_);        }
  std::vector<float>   Reco_Muon_IsoR03()                 { SetBranch("Reco_Muon_IsoR03");                 return GET(Reco_Muon_IsoR03_);                 }
  std::vector<float>   Reco_Muon_IsoR05()                 { SetBranch("Reco_Muon_IsoR05");                 return GET(Reco_Muon_IsoR05_);                 }
  std::vector<float>   Reco_Muon_Trk_sumR03Pt()           { SetBranch("Reco_Muon_Trk_sumR03Pt");           return GET(Reco_Muon_Trk_sumR03Pt_);           }
  std::vector<float>   Reco_Muon_Trk_sumR05Pt()           { SetBranch("Reco_Muon_Trk_sumR05Pt");           return GET(Reco_Muon_Trk_sumR05Pt_);           }
  UShort_t             Reco_DiMuon_N()                    { SetBranch("Reco_DiMuon_N");                    return Reco_DiMuon_N_;                         }
  VTLorentzVector      Reco_DiMuon_Mom()                  { SetBranch("Reco_DiMuon_Mom");                  return EXTRACTLV("Reco_DiMuon_Mom");           }
  std::vector<char>    Reco_DiMuon_Charge()               { SetBranch("Reco_DiMuon_Charge");               return GET(Reco_DiMuon_Charge_);               }
  std::vector<UChar_t> Reco_DiMuon_Muon1_Idx()            { SetBranch("Reco_DiMuon_Muon1_Idx");            return GET(Reco_DiMuon_Muon1_Idx_);            }
  std::vector<UChar_t> Reco_DiMuon_Muon2_Idx()            { SetBranch("Reco_DiMuon_Muon2_Idx");            return GET(Reco_DiMuon_Muon2_Idx_);            }
  std::vector<bool>    Reco_DiMuon_isCowBoy()             { SetBranch("Reco_DiMuon_isCowBoy");             return GET(Reco_DiMuon_isCowBoy_);             }
  VTVector3            Reco_DiMuon_Vertex()               { SetBranch("Reco_DiMuon_Vertex");               return EXTRACTV3("Reco_DiMuon_Vertex");        }
  std::vector<float>   Reco_DiMuon_VtxProb()              { SetBranch("Reco_DiMuon_VtxProb");              return GET(Reco_DiMuon_VtxProb_);              }
  std::vector<float>   Reco_DiMuon_DCA()                  { SetBranch("Reco_DiMuon_DCA");                  return GET(Reco_DiMuon_DCA_);                  }
  std::vector<float>   Reco_DiMuon_MassErr()              { SetBranch("Reco_DiMuon_MassErr");              return GET(Reco_DiMuon_MassErr_);              }

  // PF MUON VARIABLES
  std::vector<bool>    PF_Candidate_isPU()                { SetBranch("PF_Candidate_isPU");                return GET(PF_Candidate_isPU_);                }
  std::vector<UChar_t> PF_Candidate_Id()                  { SetBranch("PF_Candidate_Id");                  return GET(PF_Candidate_Id_);                  }
  std::vector<float>   PF_Candidate_Eta()                 { SetBranch("PF_Candidate_Eta");                 return GET(PF_Candidate_Eta_);                 }
  std::vector<float>   PF_Candidate_Phi()                 { SetBranch("PF_Candidate_Phi");                 return GET(PF_Candidate_Phi_);                 }
  std::vector<float>   PF_Candidate_Pt()                  { SetBranch("PF_Candidate_Pt");                  return GET(PF_Candidate_Pt_);                  }
  UChar_t              PF_Muon_N()                        { SetBranch("PF_Muon_N");                        return PF_Muon_N_;                             }
  VTLorentzVector      PF_Muon_Mom()                      { SetBranch("PF_Muon_Mom");                      return EXTRACTLV("PF_Muon_Mom");               }
  std::vector<char>    PF_Muon_Charge()                   { SetBranch("PF_Muon_Charge");                   return GET(PF_Muon_Charge_);                   }
  std::vector<char>    PF_Muon_Gen_Idx()                  { SetBranch("PF_Muon_Gen_Idx");                  return GET(PF_Muon_Gen_Idx_);                  }
  std::vector<char>    PF_Muon_Reco_Idx()                 { SetBranch("PF_Muon_Reco_Idx");                 return GET(PF_Muon_Reco_Idx_);                 }
  std::vector<float>   PF_Muon_IsoPFR03()                 { SetBranch("PF_Muon_IsoPFR03");                 return GET(PF_Muon_IsoPFR03_);                 }
  std::vector<float>   PF_Muon_IsoPFR03NoPUCorr()         { SetBranch("PF_Muon_IsoPFR03NoPUCorr");         return GET(PF_Muon_IsoPFR03NoPUCorr_);         }
  std::vector<float>   PF_Muon_IsoPFR04()                 { SetBranch("PF_Muon_IsoPFR04");                 return GET(PF_Muon_IsoPFR04_);                 }
  std::vector<float>   PF_Muon_IsoPFR04NoPUCorr()         { SetBranch("PF_Muon_IsoPFR04NoPUCorr");         return GET(PF_Muon_IsoPFR04NoPUCorr_);         }
  std::vector<float>   PF_Muon_EM_Chg_sumR03Pt()          { SetBranch("PF_Muon_EM_Chg_sumR03Pt");          return GET(PF_Muon_EM_Chg_sumR03Pt_);          }
  std::vector<float>   PF_Muon_EM_Chg_sumR04Pt()          { SetBranch("PF_Muon_EM_Chg_sumR04Pt");          return GET(PF_Muon_EM_Chg_sumR04Pt_);          }
  std::vector<float>   PF_Muon_EM_Neu_sumR03Et()          { SetBranch("PF_Muon_EM_Neu_sumR03Et");          return GET(PF_Muon_EM_Neu_sumR03Et_);          }
  std::vector<float>   PF_Muon_EM_Neu_sumR04Et()          { SetBranch("PF_Muon_EM_Neu_sumR04Et");          return GET(PF_Muon_EM_Neu_sumR04Et_);          }
  std::vector<float>   PF_Muon_Had_Chg_sumR03Pt()         { SetBranch("PF_Muon_Had_Chg_sumR03Pt");         return GET(PF_Muon_Had_Chg_sumR03Pt_);         }
  std::vector<float>   PF_Muon_Had_Chg_sumR04Pt()         { SetBranch("PF_Muon_Had_Chg_sumR04Pt");         return GET(PF_Muon_Had_Chg_sumR04Pt_);         }
  std::vector<float>   PF_Muon_Had_Neu_sumR03Et()         { SetBranch("PF_Muon_Had_Neu_sumR03Et");         return GET(PF_Muon_Had_Neu_sumR03Et_);         }
  std::vector<float>   PF_Muon_Had_Neu_sumR04Et()         { SetBranch("PF_Muon_Had_Neu_sumR04Et");         return GET(PF_Muon_Had_Neu_sumR04Et_);         }
  std::vector<float>   PF_Muon_Had_PU_sumR03Pt()          { SetBranch("PF_Muon_Had_PU_sumR03Pt");          return GET(PF_Muon_Had_PU_sumR03Pt_);          }
  std::vector<float>   PF_Muon_Had_PU_sumR04Pt()          { SetBranch("PF_Muon_Had_PU_sumR04Pt");          return GET(PF_Muon_Had_PU_sumR04Pt_);          }
  UShort_t             PF_DiMuon_N()                      { SetBranch("PF_DiMuon_N");                      return PF_DiMuon_N_;                           }
  VTLorentzVector      PF_DiMuon_Mom()                    { SetBranch("PF_DiMuon_Mom");                    return EXTRACTLV("PF_DiMuon_Mom");             }
  std::vector<char>    PF_DiMuon_Charge()                 { SetBranch("PF_DiMuon_Charge");                 return GET(PF_DiMuon_Charge_);                 }
  std::vector<UChar_t> PF_DiMuon_Muon1_Idx()              { SetBranch("PF_DiMuon_Muon1_Idx");              return GET(PF_DiMuon_Muon1_Idx_);              }
  std::vector<UChar_t> PF_DiMuon_Muon2_Idx()              { SetBranch("PF_DiMuon_Muon2_Idx");              return GET(PF_DiMuon_Muon2_Idx_);              }
  VTVector3            PF_DiMuon_Vertex()                 { SetBranch("PF_DiMuon_Vertex");                 return EXTRACTV3("PF_DiMuon_Vertex");          }
  std::vector<float>   PF_DiMuon_VtxProb()                { SetBranch("PF_DiMuon_VtxProb");                return GET(PF_DiMuon_VtxProb_);                }
  std::vector<float>   PF_DiMuon_DCA()                    { SetBranch("PF_DiMuon_DCA");                    return GET(PF_DiMuon_DCA_);                    }
  std::vector<float>   PF_DiMuon_MassErr()                { SetBranch("PF_DiMuon_MassErr");                return GET(PF_DiMuon_MassErr_);                }
  TVector2             PF_MET_Mom()                       { SetBranch("PF_MET_Mom");                       return GET(PF_MET_Mom_);                       }
  VTLorentzVector      PF_MuonMET_TransMom()              { SetBranch("PF_MuonMET_TransMom");              return EXTRACTLV("PF_MuonMET_TransMom");       }

  // GEN PARTICLE VARIABLES
  VTLorentzVector      Gen_Particle_Mom()                 { SetBranch("Gen_Particle_Mom");                 return EXTRACTLV("Gen_Particle_Mom");          }
  std::vector<int>     Gen_Particle_PdgId()               { SetBranch("Gen_Particle_PdgId");               return GET(Gen_Particle_PdgId_);               }
  std::vector<UChar_t> Gen_Particle_Status()              { SetBranch("Gen_Particle_Status");              return GET(Gen_Particle_Status_);              }
  UShortVecVec         Gen_Particle_Mother_Idx()          { SetBranch("Gen_Particle_Mother_Idx");          return GET(Gen_Particle_Mother_Idx_);          }
  UShortVecVec         Gen_Particle_Daughter_Idx()        { SetBranch("Gen_Particle_Daughter_Idx");        return GET(Gen_Particle_Daughter_Idx_);        }
  // GEN MUON VARIABLES
  UChar_t              Gen_Muon_N()                       { SetBranch("Gen_Muon_N");                       return Gen_Muon_N_;                            }
  VTLorentzVector      Gen_Muon_Mom()                     { SetBranch("Gen_Muon_Mom");                     return EXTRACTLV("Gen_Muon_Mom");              }
  std::vector<char>    Gen_Muon_Charge()                  { SetBranch("Gen_Muon_Charge");                  return GET(Gen_Muon_Charge_);                  }
  std::vector<UShort_t> Gen_Muon_Particle_Idx()           { SetBranch("Gen_Muon_Particle_Idx");            return GET(Gen_Muon_Particle_Idx_);            }
  std::vector<char>    Gen_Muon_Reco_Idx()                { SetBranch("Gen_Muon_Reco_Idx");                return GET(Gen_Muon_Reco_Idx_);                }
  std::vector<char>    Gen_Muon_PF_Idx()                  { SetBranch("Gen_Muon_PF_Idx");                  return GET(Gen_Muon_PF_Idx_);                  }

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
  std::vector<bool>    *Event_Trig_Fired_;
  std::vector<int>     *Event_Trig_Presc_;

  // RECO MUON POINTERS
  UChar_t              Reco_Muon_N_ = 0;
  std::vector<char>    *Reco_Muon_Charge_;
  std::vector<char>    *Reco_Muon_Gen_Idx_;
  std::vector<char>    *Reco_Muon_PF_Idx_;
  UCharVecVec          *Pat_Muon_Trig_;
  std::vector<float>   *Pat_Muon_dB_;
  std::vector<float>   *Pat_Muon_dBErr_;
  std::vector<bool>    *Reco_Muon_isPF_;
  std::vector<bool>    *Reco_Muon_isGlobal_;
  std::vector<bool>    *Reco_Muon_isTracker_;
  std::vector<bool>    *Reco_Muon_isStandAlone_;
  std::vector<bool>    *Reco_Muon_isLoose_;
  std::vector<bool>    *Reco_Muon_isMedium_;
  std::vector<bool>    *Reco_Muon_isHighPt_;
  std::vector<bool>    *Reco_Muon_isSoft_;
  std::vector<bool>    *Reco_Muon_isTight_;
  std::vector<bool>    *Reco_Muon_isArbitrated_;
  std::vector<bool>    *Reco_Muon_TrackerArbitrated_;
  std::vector<bool>    *Reco_Muon_GlobalPromptTight_;
  std::vector<bool>    *Reco_Muon_TMLastStationLoose_;
  std::vector<bool>    *Reco_Muon_TMLastStationTight_;
  std::vector<bool>    *Reco_Muon_TM2DCompatibilityLoose_;
  std::vector<bool>    *Reco_Muon_TM2DCompatibilityTight_;
  std::vector<bool>    *Reco_Muon_TMOneStationLoose_;
  std::vector<bool>    *Reco_Muon_TMOneStationTight_;
  std::vector<bool>    *Reco_Muon_GMTkChiCompatibility_;
  std::vector<bool>    *Reco_Muon_GMStaChiCompatibility_;
  std::vector<bool>    *Reco_Muon_GMTkKinkTight_;
  std::vector<bool>    *Reco_Muon_TMLastStationAngLoose_;
  std::vector<bool>    *Reco_Muon_TMLastStationAngTight_;
  std::vector<bool>    *Reco_Muon_TMOneStationAngLoose_;
  std::vector<bool>    *Reco_Muon_TMOneStationAngTight_;
  std::vector<short>   *Reco_Muon_MatchedStations_;
  std::vector<short>   *Reco_Muon_Matches_;
  std::vector<float>   *Reco_Muon_SegmentComp_;
  std::vector<float>   *Reco_Muon_Chi2Pos_;
  std::vector<float>   *Reco_Muon_TrkKink_;
  std::vector<float>   *Reco_Muon_InTrk_PtErr_;
  std::vector<bool>    *Reco_Muon_InTrk_isHighPurity_;
  std::vector<short>   *Reco_Muon_InTrk_ValidHits_;
  std::vector<short>   *Reco_Muon_InTrk_LostHits_;
  std::vector<short>   *Reco_Muon_InTrk_ValidPixHits_;
  std::vector<short>   *Reco_Muon_InTrk_TrkLayers_;
  std::vector<short>   *Reco_Muon_InTrk_PixLayers_;
  std::vector<float>   *Reco_Muon_InTrk_dXY_;
  std::vector<float>   *Reco_Muon_InTrk_dXYErr_;
  std::vector<float>   *Reco_Muon_InTrk_dZ_;
  std::vector<float>   *Reco_Muon_InTrk_dZErr_;
  std::vector<float>   *Reco_Muon_InTrk_ValFrac_;
  std::vector<float>   *Reco_Muon_InTrk_NormChi2_;
  std::vector<float>   *Reco_Muon_GlbTrk_PtErr_;
  std::vector<short>   *Reco_Muon_GlbTrk_ValidMuonHits_;
  std::vector<float>   *Reco_Muon_GlbTrk_NormChi2_;
  std::vector<char>    *Reco_Muon_BestTrk_Type_;
  std::vector<float>   *Reco_Muon_BestTrk_PtErr_;
  std::vector<float>   *Reco_Muon_BestTrk_dXY_;
  std::vector<float>   *Reco_Muon_BestTrk_dXYErr_;
  std::vector<float>   *Reco_Muon_BestTrk_dZ_;
  std::vector<float>   *Reco_Muon_BestTrk_dZErr_;
  std::vector<float>   *Reco_Muon_IsoPFR03_;
  std::vector<float>   *Reco_Muon_IsoPFR03NoPUCorr_;
  std::vector<float>   *Reco_Muon_IsoPFR04_;
  std::vector<float>   *Reco_Muon_IsoPFR04NoPUCorr_;
  std::vector<float>   *Reco_Muon_EM_Chg_sumR03Pt_;
  std::vector<float>   *Reco_Muon_EM_Chg_sumR04Pt_;
  std::vector<float>   *Reco_Muon_EM_Neu_sumR03Et_;
  std::vector<float>   *Reco_Muon_EM_Neu_sumR04Et_;
  std::vector<float>   *Reco_Muon_Had_Chg_sumR03Pt_;
  std::vector<float>   *Reco_Muon_Had_Chg_sumR04Pt_;
  std::vector<float>   *Reco_Muon_Had_Neu_sumR03Et_;
  std::vector<float>   *Reco_Muon_Had_Neu_sumR04Et_;
  std::vector<float>   *Reco_Muon_Had_PU_sumR03Pt_;
  std::vector<float>   *Reco_Muon_Had_PU_sumR04Pt_;
  std::vector<float>   *Reco_Muon_IsoR03_;
  std::vector<float>   *Reco_Muon_IsoR05_;
  std::vector<float>   *Reco_Muon_Trk_sumR03Pt_;
  std::vector<float>   *Reco_Muon_Trk_sumR05Pt_;
  UShort_t             Reco_DiMuon_N_ = 0;
  std::vector<char>    *Reco_DiMuon_Charge_;
  std::vector<UChar_t> *Reco_DiMuon_Muon1_Idx_;
  std::vector<UChar_t> *Reco_DiMuon_Muon2_Idx_;
  std::vector<bool>    *Reco_DiMuon_isCowBoy_;
  std::vector<float>   *Reco_DiMuon_VtxProb_;
  std::vector<float>   *Reco_DiMuon_DCA_;
  std::vector<float>   *Reco_DiMuon_MassErr_;

  // PF MUON BRANCHES
  std::vector<bool>    *PF_Candidate_isPU_;
  std::vector<UChar_t> *PF_Candidate_Id_;
  std::vector<float>   *PF_Candidate_Eta_;
  std::vector<float>   *PF_Candidate_Phi_;
  std::vector<float>   *PF_Candidate_Pt_;
  UChar_t              PF_Muon_N_ = 0;
  std::vector<char>    *PF_Muon_Charge_;
  std::vector<char>    *PF_Muon_Gen_Idx_;
  std::vector<char>    *PF_Muon_Reco_Idx_;
  std::vector<float>   *PF_Muon_IsoPFR03_;
  std::vector<float>   *PF_Muon_IsoPFR03NoPUCorr_;
  std::vector<float>   *PF_Muon_IsoPFR04_;
  std::vector<float>   *PF_Muon_IsoPFR04NoPUCorr_;
  std::vector<float>   *PF_Muon_EM_Chg_sumR03Pt_;
  std::vector<float>   *PF_Muon_EM_Chg_sumR04Pt_;
  std::vector<float>   *PF_Muon_EM_Neu_sumR03Et_;
  std::vector<float>   *PF_Muon_EM_Neu_sumR04Et_;
  std::vector<float>   *PF_Muon_Had_Chg_sumR03Pt_;
  std::vector<float>   *PF_Muon_Had_Chg_sumR04Pt_;
  std::vector<float>   *PF_Muon_Had_Neu_sumR03Et_;
  std::vector<float>   *PF_Muon_Had_Neu_sumR04Et_;
  std::vector<float>   *PF_Muon_Had_PU_sumR03Pt_;
  std::vector<float>   *PF_Muon_Had_PU_sumR04Pt_;
  UShort_t             PF_DiMuon_N_ = 0;
  std::vector<char>    *PF_DiMuon_Charge_;
  std::vector<UChar_t> *PF_DiMuon_Muon1_Idx_;
  std::vector<UChar_t> *PF_DiMuon_Muon2_Idx_;
  std::vector<float>   *PF_DiMuon_VtxProb_;
  std::vector<float>   *PF_DiMuon_DCA_;
  std::vector<float>   *PF_DiMuon_MassErr_;
  TVector2             *PF_MET_Mom_;

  // GEN PARTICLE POINTERS
  std::vector<int>     *Gen_Particle_PdgId_;
  std::vector<UChar_t> *Gen_Particle_Status_;
  UShortVecVec         *Gen_Particle_Mother_Idx_;
  UShortVecVec         *Gen_Particle_Daughter_Idx_;
  // GEN MUON POINTERS
  UChar_t              Gen_Muon_N_ = 0;
  std::vector<char>    *Gen_Muon_Charge_;
  std::vector<ushort>  *Gen_Muon_Particle_Idx_;
  std::vector<char>    *Gen_Muon_Reco_Idx_;
  std::vector<char>    *Gen_Muon_PF_Idx_;

  // EVENT INFO BRANCHES
  TBranch        *b_Event_Run;   //!
  TBranch        *b_Event_Lumi;   //!
  TBranch        *b_Event_Bx;   //!
  TBranch        *b_Event_Orbit;   //!
  TBranch        *b_Event_Number;   //!
  TBranch        *b_Event_nPV;   //!
  TBranch        *b_Event_PriVtx_Pos;   //!
  TBranch        *b_Event_PriVtx_Err;   //!
  TBranch        *b_Event_Trig_Fired;   //!
  TBranch        *b_Event_Trig_Presc;   //!

  // RECO MUON BRANCHES
  TBranch        *b_Reco_Muon_N;   //!
  TBranch        *b_Reco_Muon_Mom;   //!
  TBranch        *b_Reco_Muon_Charge;   //!
  TBranch        *b_Reco_Muon_Gen_Idx;   //!
  TBranch        *b_Reco_Muon_PF_Idx;   //!
  TBranch        *b_Pat_Muon_Trig;   //!
  TBranch        *b_Pat_Muon_dB;   //!
  TBranch        *b_Pat_Muon_dBErr;   //!
  TBranch        *b_Reco_Muon_isPF;   //!
  TBranch        *b_Reco_Muon_isGlobal;   //!
  TBranch        *b_Reco_Muon_isTracker;   //!
  TBranch        *b_Reco_Muon_isStandAlone;   //!
  TBranch        *b_Reco_Muon_isLoose;   //!
  TBranch        *b_Reco_Muon_isMedium;   //!
  TBranch        *b_Reco_Muon_isHighPt;   //!
  TBranch        *b_Reco_Muon_isSoft;   //!
  TBranch        *b_Reco_Muon_isTight;   //!
  TBranch        *b_Reco_Muon_isArbitrated;   //!
  TBranch        *b_Reco_Muon_TrackerArbitrated;   //!
  TBranch        *b_Reco_Muon_GlobalPromptTight;   //!
  TBranch        *b_Reco_Muon_TMLastStationLoose;   //!
  TBranch        *b_Reco_Muon_TMLastStationTight;   //!
  TBranch        *b_Reco_Muon_TM2DCompatibilityLoose;   //!
  TBranch        *b_Reco_Muon_TM2DCompatibilityTight;   //!
  TBranch        *b_Reco_Muon_TMOneStationLoose;   //!
  TBranch        *b_Reco_Muon_TMOneStationTight;   //!
  TBranch        *b_Reco_Muon_GMTkChiCompatibility;   //!
  TBranch        *b_Reco_Muon_GMStaChiCompatibility;   //!
  TBranch        *b_Reco_Muon_GMTkKinkTight;   //!
  TBranch        *b_Reco_Muon_TMLastStationAngLoose;   //!
  TBranch        *b_Reco_Muon_TMLastStationAngTight;   //!
  TBranch        *b_Reco_Muon_TMOneStationAngLoose;   //!
  TBranch        *b_Reco_Muon_TMOneStationAngTight;   //!
  TBranch        *b_Reco_Muon_MatchedStations;   //!
  TBranch        *b_Reco_Muon_Matches;   //!
  TBranch        *b_Reco_Muon_SegmentComp;   //!
  TBranch        *b_Reco_Muon_Chi2Pos;   //!
  TBranch        *b_Reco_Muon_TrkKink;   //!
  TBranch        *b_Reco_Muon_InTrk_Mom;   //!
  TBranch        *b_Reco_Muon_InTrk_PtErr;   //!
  TBranch        *b_Reco_Muon_InTrk_isHighPurity;   //!
  TBranch        *b_Reco_Muon_InTrk_ValidHits;   //!
  TBranch        *b_Reco_Muon_InTrk_LostHits;   //!
  TBranch        *b_Reco_Muon_InTrk_ValidPixHits;   //!
  TBranch        *b_Reco_Muon_InTrk_TrkLayers;   //!
  TBranch        *b_Reco_Muon_InTrk_PixLayers;   //!
  TBranch        *b_Reco_Muon_InTrk_dXY;   //!
  TBranch        *b_Reco_Muon_InTrk_dXYErr;   //!
  TBranch        *b_Reco_Muon_InTrk_dZ;   //!
  TBranch        *b_Reco_Muon_InTrk_dZErr;   //!
  TBranch        *b_Reco_Muon_InTrk_ValFrac;   //!
  TBranch        *b_Reco_Muon_InTrk_NormChi2;   //!
  TBranch        *b_Reco_Muon_GlbTrk_Mom;   //!
  TBranch        *b_Reco_Muon_GlbTrk_PtErr;   //!
  TBranch        *b_Reco_Muon_GlbTrk_ValidMuonHits;   //!
  TBranch        *b_Reco_Muon_GlbTrk_NormChi2;   //!
  TBranch        *b_Reco_Muon_BestTrk_Type;   //!
  TBranch        *b_Reco_Muon_BestTrk_Mom;   //!
  TBranch        *b_Reco_Muon_BestTrk_Vertex;   //!
  TBranch        *b_Reco_Muon_BestTrk_PtErr;   //!
  TBranch        *b_Reco_Muon_BestTrk_dXY;   //!
  TBranch        *b_Reco_Muon_BestTrk_dXYErr;   //!
  TBranch        *b_Reco_Muon_BestTrk_dZ;   //!
  TBranch        *b_Reco_Muon_BestTrk_dZErr;   //!
  TBranch        *b_Reco_Muon_IsoPFR03;   //!
  TBranch        *b_Reco_Muon_IsoPFR03NoPUCorr;   //!
  TBranch        *b_Reco_Muon_IsoPFR04;   //!
  TBranch        *b_Reco_Muon_IsoPFR04NoPUCorr;   //!
  TBranch        *b_Reco_Muon_EM_Chg_sumR03Pt;   //!
  TBranch        *b_Reco_Muon_EM_Chg_sumR04Pt;   //!
  TBranch        *b_Reco_Muon_EM_Neu_sumR03Et;   //!
  TBranch        *b_Reco_Muon_EM_Neu_sumR04Et;   //!
  TBranch        *b_Reco_Muon_Had_Chg_sumR03Pt;   //!
  TBranch        *b_Reco_Muon_Had_Chg_sumR04Pt;   //!
  TBranch        *b_Reco_Muon_Had_Neu_sumR03Et;   //!
  TBranch        *b_Reco_Muon_Had_Neu_sumR04Et;   //!
  TBranch        *b_Reco_Muon_Had_PU_sumR03Pt;   //!
  TBranch        *b_Reco_Muon_Had_PU_sumR04Pt;   //!
  TBranch        *b_Reco_Muon_IsoR03;   //!
  TBranch        *b_Reco_Muon_IsoR05;   //!
  TBranch        *b_Reco_Muon_Trk_sumR03Pt;   //!
  TBranch        *b_Reco_Muon_Trk_sumR05Pt;   //!
  TBranch        *b_Reco_DiMuon_N;   //!
  TBranch        *b_Reco_DiMuon_Mom;   //!
  TBranch        *b_Reco_DiMuon_Charge;   //!
  TBranch        *b_Reco_DiMuon_Muon1_Idx;   //!
  TBranch        *b_Reco_DiMuon_Muon2_Idx;   //!
  TBranch        *b_Reco_DiMuon_isCowBoy;   //!
  TBranch        *b_Reco_DiMuon_Vertex;   //!
  TBranch        *b_Reco_DiMuon_VtxProb;   //!
  TBranch        *b_Reco_DiMuon_DCA;   //!
  TBranch        *b_Reco_DiMuon_MassErr;   //!
  
  // PF MUON BRANCHES
  TBranch        *b_PF_Candidate_isPU;   //!
  TBranch        *b_PF_Candidate_Id;   //!
  TBranch        *b_PF_Candidate_Eta;   //!
  TBranch        *b_PF_Candidate_Phi;   //!
  TBranch        *b_PF_Candidate_Pt;   //!
  TBranch        *b_PF_Muon_N;   //!
  TBranch        *b_PF_Muon_Mom;   //!
  TBranch        *b_PF_Muon_Charge;   //!
  TBranch        *b_PF_Muon_Gen_Idx;   //!
  TBranch        *b_PF_Muon_Reco_Idx;   //!
  TBranch        *b_PF_Muon_IsoPFR03;   //!
  TBranch        *b_PF_Muon_IsoPFR03NoPUCorr;   //!
  TBranch        *b_PF_Muon_IsoPFR04;   //!
  TBranch        *b_PF_Muon_IsoPFR04NoPUCorr;   //!
  TBranch        *b_PF_Muon_EM_Chg_sumR03Pt;   //!
  TBranch        *b_PF_Muon_EM_Chg_sumR04Pt;   //!
  TBranch        *b_PF_Muon_EM_Neu_sumR03Et;   //!
  TBranch        *b_PF_Muon_EM_Neu_sumR04Et;   //!
  TBranch        *b_PF_Muon_Had_Chg_sumR03Pt;   //!
  TBranch        *b_PF_Muon_Had_Chg_sumR04Pt;   //!
  TBranch        *b_PF_Muon_Had_Neu_sumR03Et;   //!
  TBranch        *b_PF_Muon_Had_Neu_sumR04Et;   //!
  TBranch        *b_PF_Muon_Had_PU_sumR03Pt;   //!
  TBranch        *b_PF_Muon_Had_PU_sumR04Pt;   //!
  TBranch        *b_PF_DiMuon_N;   //!
  TBranch        *b_PF_DiMuon_Mom;   //!
  TBranch        *b_PF_DiMuon_Charge;   //!
  TBranch        *b_PF_DiMuon_Muon1_Idx;   //!
  TBranch        *b_PF_DiMuon_Muon2_Idx;   //!
  TBranch        *b_PF_DiMuon_Vertex;   //!
  TBranch        *b_PF_DiMuon_VtxProb;   //!
  TBranch        *b_PF_DiMuon_DCA;   //!
  TBranch        *b_PF_DiMuon_MassErr;   //!
  TBranch        *b_PF_MET_Mom;   //!
  TBranch        *b_PF_MuonMET_TransMom;   //!
  
  // GEN PARTICLE BRANCHES
  TBranch        *b_Gen_Particle_Mom;   //!
  TBranch        *b_Gen_Particle_PdgId;   //!
  TBranch        *b_Gen_Particle_Status;   //!
  TBranch        *b_Gen_Particle_Mother_Idx;   //!
  TBranch        *b_Gen_Particle_Daughter_Idx;   //!
  // GEN MUON BRANCHES
  TBranch        *b_Gen_Muon_N;   //!
  TBranch        *b_Gen_Muon_Mom;   //!
  TBranch        *b_Gen_Muon_Charge;   //!
  TBranch        *b_Gen_Muon_Particle_Idx;   //!
  TBranch        *b_Gen_Muon_Reco_Idx;   //!
  TBranch        *b_Gen_Muon_PF_Idx;   //!
};

HiMuonTree::HiMuonTree() : fChain_(0)
{
}

HiMuonTree::~HiMuonTree()
{
  if (fChain_ && fChain_->GetCurrentFile()) delete fChain_->GetCurrentFile();
}

Bool_t HiMuonTree::GetTree(const std::string& fileName, TTree* tree)
{
  // Open the input files
  TFile *f = TFile::Open(fileName.c_str());
  if (!f || !f->IsOpen()) return false;
  // Extract the input TTrees
  fChainM_.clear();
  TDirectory * dir;
  if (fileName.find("root://")!=std::string::npos) dir = (TDirectory*)f->Get("muonAna");
  else dir = (TDirectory*)f->Get((fileName+":/muonAna").c_str());
  if (!dir) return false;
  if (dir->GetListOfKeys()->Contains("Muon_Event")) dir->GetObject("Muon_Event",fChainM_["Event"]);
  if (dir->GetListOfKeys()->Contains("Muon_Reco"))  dir->GetObject("Muon_Reco", fChainM_["Reco"]);
  if (dir->GetListOfKeys()->Contains("Muon_PF") )   dir->GetObject("Muon_PF",   fChainM_["PF"]  );
  if (dir->GetListOfKeys()->Contains("Muon_Gen") )  dir->GetObject("Muon_Gen",  fChainM_["Gen"] );
  if (fChainM_.count("Reco")) fChainM_["Pat"] = fChainM_.at("Reco");
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

Int_t HiMuonTree::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  entry_ = entry;
  if (LoadTree(entry_) < 0) return -1;
  Clear();
  return LoadEntry();
}

Long64_t HiMuonTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain_) return -5;
   Long64_t centry = fChain_->LoadTree(entry);
   return centry;
}

char HiMuonTree::GetBranchStatus(const std::string& n)
{
  std::string type = n.substr(0, n.find("_"));
  if ( !(fChainM_.at(type)) || !(fChainM_.at(type)->GetBranch(n.c_str())) ) return -1;
  return fChainM_.at(type)->GetBranchStatus(n.c_str());
}

void HiMuonTree::SetBranch(const std::string& n)
{
  std::string type = n.substr(0, n.find("_"));
  if (GetBranchStatus(n) == 0) {
    fChainM_.at(type)->SetBranchStatus(n.c_str(), 1);
    LoadEntry(); // Needed for the first entry
  }
}

void HiMuonTree::InitTree(void)
{
  // Generate the dictionary's needed
  gInterpreter->GenerateDictionary("vector<vector<UChar_t>>","vector");
  gInterpreter->GenerateDictionary("vector<vector<UShort_t>>","vector");

  // INITIALIZE TCLONESARRAY
  TClonesArray_.clear();
  
  // INITIALIZE EVENT INFO POINTERS
  Event_PriVtx_Pos_ = 0;
  Event_PriVtx_Err_ = 0;
  Event_Trig_Fired_ = 0;
  Event_Trig_Presc_ = 0;

  // INITIALIZE RECO MUON POINTERS
  Reco_Muon_Charge_ = 0;
  Reco_Muon_Gen_Idx_ = 0;
  Reco_Muon_PF_Idx_ = 0;
  Pat_Muon_Trig_ = 0;
  Pat_Muon_dB_ = 0;
  Pat_Muon_dBErr_ = 0;
  Reco_Muon_isPF_ = 0;
  Reco_Muon_isGlobal_ = 0;
  Reco_Muon_isTracker_ = 0;
  Reco_Muon_isStandAlone_ = 0;
  Reco_Muon_isLoose_ = 0;
  Reco_Muon_isMedium_ = 0;
  Reco_Muon_isHighPt_ = 0;
  Reco_Muon_isSoft_ = 0;
  Reco_Muon_isTight_ = 0;
  Reco_Muon_isArbitrated_ = 0;
  Reco_Muon_TrackerArbitrated_ = 0;
  Reco_Muon_GlobalPromptTight_ = 0;
  Reco_Muon_TMLastStationLoose_ = 0;
  Reco_Muon_TMLastStationTight_ = 0;
  Reco_Muon_TM2DCompatibilityLoose_ = 0;
  Reco_Muon_TM2DCompatibilityTight_ = 0;
  Reco_Muon_TMOneStationLoose_ = 0;
  Reco_Muon_TMOneStationTight_ = 0;
  Reco_Muon_GMTkChiCompatibility_ = 0;
  Reco_Muon_GMStaChiCompatibility_ = 0;
  Reco_Muon_GMTkKinkTight_ = 0;
  Reco_Muon_TMLastStationAngLoose_ = 0;
  Reco_Muon_TMLastStationAngTight_ = 0;
  Reco_Muon_TMOneStationAngLoose_ = 0;
  Reco_Muon_TMOneStationAngTight_ = 0;
  Reco_Muon_MatchedStations_ = 0;
  Reco_Muon_Matches_ = 0;
  Reco_Muon_SegmentComp_ = 0;
  Reco_Muon_Chi2Pos_ = 0;
  Reco_Muon_TrkKink_ = 0;
  Reco_Muon_InTrk_PtErr_ = 0;
  Reco_Muon_InTrk_isHighPurity_ = 0;
  Reco_Muon_InTrk_ValidHits_ = 0;
  Reco_Muon_InTrk_LostHits_ = 0;
  Reco_Muon_InTrk_ValidPixHits_ = 0;
  Reco_Muon_InTrk_TrkLayers_ = 0;
  Reco_Muon_InTrk_PixLayers_ = 0;
  Reco_Muon_InTrk_dXY_ = 0;
  Reco_Muon_InTrk_dXYErr_ = 0;
  Reco_Muon_InTrk_dZ_ = 0;
  Reco_Muon_InTrk_dZErr_ = 0;
  Reco_Muon_InTrk_ValFrac_ = 0;
  Reco_Muon_InTrk_NormChi2_ = 0;
  Reco_Muon_GlbTrk_PtErr_ = 0;
  Reco_Muon_GlbTrk_ValidMuonHits_ = 0;
  Reco_Muon_GlbTrk_NormChi2_ = 0;
  Reco_Muon_BestTrk_Type_ = 0;
  Reco_Muon_BestTrk_PtErr_ = 0;
  Reco_Muon_BestTrk_dXY_ = 0;
  Reco_Muon_BestTrk_dXYErr_ = 0;
  Reco_Muon_BestTrk_dZ_ = 0;
  Reco_Muon_BestTrk_dZErr_ = 0;
  Reco_Muon_IsoPFR03_ = 0;
  Reco_Muon_IsoPFR03NoPUCorr_ = 0;
  Reco_Muon_IsoPFR04_ = 0;
  Reco_Muon_IsoPFR04NoPUCorr_ = 0;
  Reco_Muon_EM_Chg_sumR03Pt_ = 0;
  Reco_Muon_EM_Chg_sumR04Pt_ = 0;
  Reco_Muon_EM_Neu_sumR03Et_ = 0;
  Reco_Muon_EM_Neu_sumR04Et_ = 0;
  Reco_Muon_Had_Chg_sumR03Pt_ = 0;
  Reco_Muon_Had_Chg_sumR04Pt_ = 0;
  Reco_Muon_Had_Neu_sumR03Et_ = 0;
  Reco_Muon_Had_Neu_sumR04Et_ = 0;
  Reco_Muon_Had_PU_sumR03Pt_ = 0;
  Reco_Muon_Had_PU_sumR04Pt_ = 0;
  Reco_Muon_IsoR03_ = 0;
  Reco_Muon_IsoR05_ = 0;
  Reco_Muon_Trk_sumR03Pt_ = 0;
  Reco_Muon_Trk_sumR05Pt_ = 0;
  Reco_DiMuon_Charge_ = 0;
  Reco_DiMuon_Muon1_Idx_ = 0;
  Reco_DiMuon_Muon2_Idx_ = 0;
  Reco_DiMuon_isCowBoy_ = 0;
  Reco_DiMuon_VtxProb_ = 0;
  Reco_DiMuon_DCA_ = 0;
  Reco_DiMuon_MassErr_ = 0;

  // INITIALIZE PF MUON POINTERS
  PF_Candidate_isPU_ = 0;
  PF_Candidate_Id_ = 0;
  PF_Candidate_Eta_ = 0;
  PF_Candidate_Phi_ = 0;
  PF_Candidate_Pt_ = 0;
  PF_Muon_Charge_ = 0;
  PF_Muon_Gen_Idx_ = 0;
  PF_Muon_Reco_Idx_ = 0;
  PF_Muon_IsoPFR03_ = 0;
  PF_Muon_IsoPFR03NoPUCorr_ = 0;
  PF_Muon_IsoPFR04_ = 0;
  PF_Muon_IsoPFR04NoPUCorr_ = 0;
  PF_Muon_EM_Chg_sumR03Pt_ = 0;
  PF_Muon_EM_Chg_sumR04Pt_ = 0;
  PF_Muon_EM_Neu_sumR03Et_ = 0;
  PF_Muon_EM_Neu_sumR04Et_ = 0;
  PF_Muon_Had_Chg_sumR03Pt_ = 0;
  PF_Muon_Had_Chg_sumR04Pt_ = 0;
  PF_Muon_Had_Neu_sumR03Et_ = 0;
  PF_Muon_Had_Neu_sumR04Et_ = 0;
  PF_Muon_Had_PU_sumR03Pt_ = 0;
  PF_Muon_Had_PU_sumR04Pt_ = 0;
  PF_DiMuon_Charge_ = 0;
  PF_DiMuon_Muon1_Idx_ = 0;
  PF_DiMuon_Muon2_Idx_ = 0;
  PF_DiMuon_VtxProb_ = 0;
  PF_DiMuon_DCA_ = 0;
  PF_DiMuon_MassErr_ = 0;
  PF_MET_Mom_ = 0;

  // INITIALIZE GEN PARTICLE POINTERS
  Gen_Particle_PdgId_ = 0;
  Gen_Particle_Status_ = 0;
  Gen_Particle_Mother_Idx_ = 0;
  Gen_Particle_Daughter_Idx_ = 0;
  // INITIALIZE GEN MUON POINTERS
  Gen_Muon_Charge_ = 0;
  Gen_Muon_Particle_Idx_ = 0;
  Gen_Muon_Reco_Idx_ = 0;
  Gen_Muon_PF_Idx_ = 0;

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
    if (fChainM_["Event"]->GetBranch("Event_Trig_Fired"))                fChainM_["Event"]->SetBranchAddress("Event_Trig_Fired", &Event_Trig_Fired_, &b_Event_Trig_Fired);
    if (fChainM_["Event"]->GetBranch("Event_Trig_Presc"))                fChainM_["Event"]->SetBranchAddress("Event_Trig_Presc", &Event_Trig_Presc_, &b_Event_Trig_Presc);
    // Set All Branches to Status 0
    fChainM_["Event"]->SetBranchStatus("*",0);
  }

  // SET RECO MUON BRANCHES
  if (fChainM_.count("Reco")>0) {
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_N"))                      fChainM_["Reco"]->SetBranchAddress("Reco_Muon_N", &Reco_Muon_N_, &b_Reco_Muon_N);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_Mom"))                    fChainM_["Reco"]->SetBranchAddress("Reco_Muon_Mom", &(TClonesArray_["Reco_Muon_Mom"]), &b_Reco_Muon_Mom);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_Charge"))                 fChainM_["Reco"]->SetBranchAddress("Reco_Muon_Charge", &Reco_Muon_Charge_, &b_Reco_Muon_Charge);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_Gen_Idx"))                fChainM_["Reco"]->SetBranchAddress("Reco_Muon_Gen_Idx", &Reco_Muon_Gen_Idx_, &b_Reco_Muon_Gen_Idx);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_PF_Idx"))                 fChainM_["Reco"]->SetBranchAddress("Reco_Muon_PF_Idx", &Reco_Muon_PF_Idx_, &b_Reco_Muon_PF_Idx);
    if (fChainM_["Reco"]->GetBranch("Pat_Muon_Trig"))                    fChainM_["Reco"]->SetBranchAddress("Pat_Muon_Trig", &Pat_Muon_Trig_, &b_Pat_Muon_Trig);
    if (fChainM_["Reco"]->GetBranch("Pat_Muon_dB"))                      fChainM_["Reco"]->SetBranchAddress("Pat_Muon_dB", &Pat_Muon_dB_, &b_Pat_Muon_dB);
    if (fChainM_["Reco"]->GetBranch("Pat_Muon_dBErr"))                   fChainM_["Reco"]->SetBranchAddress("Pat_Muon_dBErr", &Pat_Muon_dBErr_, &b_Pat_Muon_dBErr);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_isPF"))                   fChainM_["Reco"]->SetBranchAddress("Reco_Muon_isPF", &Reco_Muon_isPF_, &b_Reco_Muon_isPF);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_isGlobal"))               fChainM_["Reco"]->SetBranchAddress("Reco_Muon_isGlobal", &Reco_Muon_isGlobal_, &b_Reco_Muon_isGlobal);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_isTracker"))              fChainM_["Reco"]->SetBranchAddress("Reco_Muon_isTracker", &Reco_Muon_isTracker_, &b_Reco_Muon_isTracker);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_isStandAlone"))           fChainM_["Reco"]->SetBranchAddress("Reco_Muon_isStandAlone", &Reco_Muon_isStandAlone_, &b_Reco_Muon_isStandAlone);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_isLoose"))                fChainM_["Reco"]->SetBranchAddress("Reco_Muon_isLoose", &Reco_Muon_isLoose_, &b_Reco_Muon_isLoose);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_isMedium"))               fChainM_["Reco"]->SetBranchAddress("Reco_Muon_isMedium", &Reco_Muon_isMedium_, &b_Reco_Muon_isMedium);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_isHighPt"))               fChainM_["Reco"]->SetBranchAddress("Reco_Muon_isHighPt", &Reco_Muon_isHighPt_, &b_Reco_Muon_isHighPt);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_isSoft"))                 fChainM_["Reco"]->SetBranchAddress("Reco_Muon_isSoft", &Reco_Muon_isSoft_, &b_Reco_Muon_isSoft);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_isTight"))                fChainM_["Reco"]->SetBranchAddress("Reco_Muon_isTight", &Reco_Muon_isTight_, &b_Reco_Muon_isTight);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_isArbitrated"))           fChainM_["Reco"]->SetBranchAddress("Reco_Muon_isArbitrated", &Reco_Muon_isArbitrated_, &b_Reco_Muon_isArbitrated);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_TrackerArbitrated"))      fChainM_["Reco"]->SetBranchAddress("Reco_Muon_TrackerArbitrated", &Reco_Muon_TrackerArbitrated_, &b_Reco_Muon_TrackerArbitrated);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_GlobalPromptTight"))      fChainM_["Reco"]->SetBranchAddress("Reco_Muon_GlobalPromptTight", &Reco_Muon_GlobalPromptTight_, &b_Reco_Muon_GlobalPromptTight);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_TMLastStationLoose"))     fChainM_["Reco"]->SetBranchAddress("Reco_Muon_TMLastStationLoose", &Reco_Muon_TMLastStationLoose_, &b_Reco_Muon_TMLastStationLoose);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_TMLastStationTight"))     fChainM_["Reco"]->SetBranchAddress("Reco_Muon_TMLastStationTight", &Reco_Muon_TMLastStationTight_, &b_Reco_Muon_TMLastStationTight);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_TM2DCompatibilityLoose")) fChainM_["Reco"]->SetBranchAddress("Reco_Muon_TM2DCompatibilityLoose", &Reco_Muon_TM2DCompatibilityLoose_, &b_Reco_Muon_TM2DCompatibilityLoose);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_TM2DCompatibilityTight")) fChainM_["Reco"]->SetBranchAddress("Reco_Muon_TM2DCompatibilityTight", &Reco_Muon_TM2DCompatibilityTight_, &b_Reco_Muon_TM2DCompatibilityTight);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_TMOneStationLoose"))      fChainM_["Reco"]->SetBranchAddress("Reco_Muon_TMOneStationLoose", &Reco_Muon_TMOneStationLoose_, &b_Reco_Muon_TMOneStationLoose);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_TMOneStationTight"))      fChainM_["Reco"]->SetBranchAddress("Reco_Muon_TMOneStationTight", &Reco_Muon_TMOneStationTight_, &b_Reco_Muon_TMOneStationTight);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_GMTkChiCompatibility"))   fChainM_["Reco"]->SetBranchAddress("Reco_Muon_GMTkChiCompatibility", &Reco_Muon_GMTkChiCompatibility_, &b_Reco_Muon_GMTkChiCompatibility);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_GMStaChiCompatibility"))  fChainM_["Reco"]->SetBranchAddress("Reco_Muon_GMStaChiCompatibility", &Reco_Muon_GMStaChiCompatibility_, &b_Reco_Muon_GMStaChiCompatibility);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_GMTkKinkTight"))          fChainM_["Reco"]->SetBranchAddress("Reco_Muon_GMTkKinkTight", &Reco_Muon_GMTkKinkTight_, &b_Reco_Muon_GMTkKinkTight);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_TMLastStationAngLoose"))  fChainM_["Reco"]->SetBranchAddress("Reco_Muon_TMLastStationAngLoose", &Reco_Muon_TMLastStationAngLoose_, &b_Reco_Muon_TMLastStationAngLoose);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_TMLastStationAngTight"))  fChainM_["Reco"]->SetBranchAddress("Reco_Muon_TMLastStationAngTight", &Reco_Muon_TMLastStationAngTight_, &b_Reco_Muon_TMLastStationAngTight);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_TMOneStationAngLoose"))   fChainM_["Reco"]->SetBranchAddress("Reco_Muon_TMOneStationAngLoose", &Reco_Muon_TMOneStationAngLoose_, &b_Reco_Muon_TMOneStationAngLoose);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_TMOneStationAngTight"))   fChainM_["Reco"]->SetBranchAddress("Reco_Muon_TMOneStationAngTight", &Reco_Muon_TMOneStationAngTight_, &b_Reco_Muon_TMOneStationAngTight);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_MatchedStations"))        fChainM_["Reco"]->SetBranchAddress("Reco_Muon_MatchedStations", &Reco_Muon_MatchedStations_, &b_Reco_Muon_MatchedStations);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_Matches"))                fChainM_["Reco"]->SetBranchAddress("Reco_Muon_Matches", &Reco_Muon_Matches_, &b_Reco_Muon_Matches);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_SegmentComp"))            fChainM_["Reco"]->SetBranchAddress("Reco_Muon_SegmentComp", &Reco_Muon_SegmentComp_, &b_Reco_Muon_SegmentComp);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_Chi2Pos"))                fChainM_["Reco"]->SetBranchAddress("Reco_Muon_Chi2Pos", &Reco_Muon_Chi2Pos_, &b_Reco_Muon_Chi2Pos);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_TrkKink"))                fChainM_["Reco"]->SetBranchAddress("Reco_Muon_TrkKink", &Reco_Muon_TrkKink_, &b_Reco_Muon_TrkKink);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_InTrk_Mom"))              fChainM_["Reco"]->SetBranchAddress("Reco_Muon_InTrk_Mom", &(TClonesArray_["Reco_Muon_InTrk_Mom"]), &b_Reco_Muon_InTrk_Mom);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_InTrk_PtErr"))            fChainM_["Reco"]->SetBranchAddress("Reco_Muon_InTrk_PtErr", &Reco_Muon_InTrk_PtErr_, &b_Reco_Muon_InTrk_PtErr);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_InTrk_isHighPurity"))     fChainM_["Reco"]->SetBranchAddress("Reco_Muon_InTrk_isHighPurity", &Reco_Muon_InTrk_isHighPurity_, &b_Reco_Muon_InTrk_isHighPurity);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_InTrk_ValidHits"))        fChainM_["Reco"]->SetBranchAddress("Reco_Muon_InTrk_ValidHits", &Reco_Muon_InTrk_ValidHits_, &b_Reco_Muon_InTrk_ValidHits);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_InTrk_LostHits"))         fChainM_["Reco"]->SetBranchAddress("Reco_Muon_InTrk_LostHits", &Reco_Muon_InTrk_LostHits_, &b_Reco_Muon_InTrk_LostHits);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_InTrk_ValidPixHits"))     fChainM_["Reco"]->SetBranchAddress("Reco_Muon_InTrk_ValidPixHits", &Reco_Muon_InTrk_ValidPixHits_, &b_Reco_Muon_InTrk_ValidPixHits);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_InTrk_TrkLayers"))        fChainM_["Reco"]->SetBranchAddress("Reco_Muon_InTrk_TrkLayers", &Reco_Muon_InTrk_TrkLayers_, &b_Reco_Muon_InTrk_TrkLayers);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_InTrk_PixLayers"))        fChainM_["Reco"]->SetBranchAddress("Reco_Muon_InTrk_PixLayers", &Reco_Muon_InTrk_PixLayers_, &b_Reco_Muon_InTrk_PixLayers);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_InTrk_dXY"))              fChainM_["Reco"]->SetBranchAddress("Reco_Muon_InTrk_dXY", &Reco_Muon_InTrk_dXY_, &b_Reco_Muon_InTrk_dXY);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_InTrk_dXYErr"))           fChainM_["Reco"]->SetBranchAddress("Reco_Muon_InTrk_dXYErr", &Reco_Muon_InTrk_dXYErr_, &b_Reco_Muon_InTrk_dXYErr);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_InTrk_dZ"))               fChainM_["Reco"]->SetBranchAddress("Reco_Muon_InTrk_dZ", &Reco_Muon_InTrk_dZ_, &b_Reco_Muon_InTrk_dZ);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_InTrk_dZErr"))            fChainM_["Reco"]->SetBranchAddress("Reco_Muon_InTrk_dZErr", &Reco_Muon_InTrk_dZErr_, &b_Reco_Muon_InTrk_dZErr);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_InTrk_ValFrac"))          fChainM_["Reco"]->SetBranchAddress("Reco_Muon_InTrk_ValFrac", &Reco_Muon_InTrk_ValFrac_, &b_Reco_Muon_InTrk_ValFrac);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_InTrk_NormChi2"))         fChainM_["Reco"]->SetBranchAddress("Reco_Muon_InTrk_NormChi2", &Reco_Muon_InTrk_NormChi2_, &b_Reco_Muon_InTrk_NormChi2);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_GlbTrk_Mom"))             fChainM_["Reco"]->SetBranchAddress("Reco_Muon_GlbTrk_Mom", &(TClonesArray_["Reco_Muon_GlbTrk_Mom"]), &b_Reco_Muon_GlbTrk_Mom);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_GlbTrk_PtErr"))           fChainM_["Reco"]->SetBranchAddress("Reco_Muon_GlbTrk_PtErr", &Reco_Muon_GlbTrk_PtErr_, &b_Reco_Muon_GlbTrk_PtErr);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_GlbTrk_ValidMuonHits"))   fChainM_["Reco"]->SetBranchAddress("Reco_Muon_GlbTrk_ValidMuonHits", &Reco_Muon_GlbTrk_ValidMuonHits_, &b_Reco_Muon_GlbTrk_ValidMuonHits);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_GlbTrk_NormChi2"))        fChainM_["Reco"]->SetBranchAddress("Reco_Muon_GlbTrk_NormChi2", &Reco_Muon_GlbTrk_NormChi2_, &b_Reco_Muon_GlbTrk_NormChi2);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_BestTrk_Type"))           fChainM_["Reco"]->SetBranchAddress("Reco_Muon_BestTrk_Type", &Reco_Muon_BestTrk_Type_, &b_Reco_Muon_BestTrk_Type);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_BestTrk_Mom"))            fChainM_["Reco"]->SetBranchAddress("Reco_Muon_BestTrk_Mom", &(TClonesArray_["Reco_Muon_BestTrk_Mom"]), &b_Reco_Muon_BestTrk_Mom);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_BestTrk_Vertex"))         fChainM_["Reco"]->SetBranchAddress("Reco_Muon_BestTrk_Vertex", &(TClonesArray_["Reco_Muon_BestTrk_Vertex"]), &b_Reco_Muon_BestTrk_Vertex);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_BestTrk_PtErr"))          fChainM_["Reco"]->SetBranchAddress("Reco_Muon_BestTrk_PtErr", &Reco_Muon_BestTrk_PtErr_, &b_Reco_Muon_BestTrk_PtErr);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_BestTrk_dXY"))            fChainM_["Reco"]->SetBranchAddress("Reco_Muon_BestTrk_dXY", &Reco_Muon_BestTrk_dXY_, &b_Reco_Muon_BestTrk_dXY);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_BestTrk_dXYErr"))         fChainM_["Reco"]->SetBranchAddress("Reco_Muon_BestTrk_dXYErr", &Reco_Muon_BestTrk_dXYErr_, &b_Reco_Muon_BestTrk_dXYErr);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_BestTrk_dZ"))             fChainM_["Reco"]->SetBranchAddress("Reco_Muon_BestTrk_dZ", &Reco_Muon_BestTrk_dZ_, &b_Reco_Muon_BestTrk_dZ);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_BestTrk_dZErr"))          fChainM_["Reco"]->SetBranchAddress("Reco_Muon_BestTrk_dZErr", &Reco_Muon_BestTrk_dZErr_, &b_Reco_Muon_BestTrk_dZErr);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_IsoPFR03"))               fChainM_["Reco"]->SetBranchAddress("Reco_Muon_IsoPFR03", &Reco_Muon_IsoPFR03_, &b_Reco_Muon_IsoPFR03);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_IsoPFR03NoPUCorr"))       fChainM_["Reco"]->SetBranchAddress("Reco_Muon_IsoPFR03NoPUCorr", &Reco_Muon_IsoPFR03NoPUCorr_, &b_Reco_Muon_IsoPFR03NoPUCorr);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_IsoPFR04"))               fChainM_["Reco"]->SetBranchAddress("Reco_Muon_IsoPFR04", &Reco_Muon_IsoPFR04_, &b_Reco_Muon_IsoPFR04);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_IsoPFR04NoPUCorr"))       fChainM_["Reco"]->SetBranchAddress("Reco_Muon_IsoPFR04NoPUCorr", &Reco_Muon_IsoPFR04NoPUCorr_, &b_Reco_Muon_IsoPFR04NoPUCorr);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_EM_Chg_sumR03Pt"))        fChainM_["Reco"]->SetBranchAddress("Reco_Muon_EM_Chg_sumR03Pt", &Reco_Muon_EM_Chg_sumR03Pt_, &b_Reco_Muon_EM_Chg_sumR03Pt);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_EM_Chg_sumR04Pt"))        fChainM_["Reco"]->SetBranchAddress("Reco_Muon_EM_Chg_sumR04Pt", &Reco_Muon_EM_Chg_sumR04Pt_, &b_Reco_Muon_EM_Chg_sumR04Pt);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_EM_Neu_sumR03Et"))        fChainM_["Reco"]->SetBranchAddress("Reco_Muon_EM_Neu_sumR03Et", &Reco_Muon_EM_Neu_sumR03Et_, &b_Reco_Muon_EM_Neu_sumR03Et);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_EM_Neu_sumR04E"))         fChainM_["Reco"]->SetBranchAddress("Reco_Muon_EM_Neu_sumR04Et", &Reco_Muon_EM_Neu_sumR04Et_, &b_Reco_Muon_EM_Neu_sumR04Et);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_Had_Chg_sumR03Et"))       fChainM_["Reco"]->SetBranchAddress("Reco_Muon_Had_Chg_sumR03Pt", &Reco_Muon_Had_Chg_sumR03Pt_, &b_Reco_Muon_Had_Chg_sumR03Pt);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_Had_Chg_sumR04Pt"))       fChainM_["Reco"]->SetBranchAddress("Reco_Muon_Had_Chg_sumR04Pt", &Reco_Muon_Had_Chg_sumR04Pt_, &b_Reco_Muon_Had_Chg_sumR04Pt);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_Had_Neu_sumR03Et"))       fChainM_["Reco"]->SetBranchAddress("Reco_Muon_Had_Neu_sumR03Et", &Reco_Muon_Had_Neu_sumR03Et_, &b_Reco_Muon_Had_Neu_sumR03Et);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_Had_Neu_sumR04Et"))       fChainM_["Reco"]->SetBranchAddress("Reco_Muon_Had_Neu_sumR04Et", &Reco_Muon_Had_Neu_sumR04Et_, &b_Reco_Muon_Had_Neu_sumR04Et);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_Had_PU_sumR03Pt"))        fChainM_["Reco"]->SetBranchAddress("Reco_Muon_Had_PU_sumR03Pt", &Reco_Muon_Had_PU_sumR03Pt_, &b_Reco_Muon_Had_PU_sumR03Pt);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_Had_PU_sumR04Pt"))        fChainM_["Reco"]->SetBranchAddress("Reco_Muon_Had_PU_sumR04Pt", &Reco_Muon_Had_PU_sumR04Pt_, &b_Reco_Muon_Had_PU_sumR04Pt);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_IsoR03"))                 fChainM_["Reco"]->SetBranchAddress("Reco_Muon_IsoR03", &Reco_Muon_IsoR03_, &b_Reco_Muon_IsoR03);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_IsoR05"))                 fChainM_["Reco"]->SetBranchAddress("Reco_Muon_IsoR05", &Reco_Muon_IsoR05_, &b_Reco_Muon_IsoR05);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_Trk_sumR03Pt"))           fChainM_["Reco"]->SetBranchAddress("Reco_Muon_Trk_sumR03Pt", &Reco_Muon_Trk_sumR03Pt_, &b_Reco_Muon_Trk_sumR03Pt);
    if (fChainM_["Reco"]->GetBranch("Reco_Muon_Trk_sumR05Pt"))           fChainM_["Reco"]->SetBranchAddress("Reco_Muon_Trk_sumR05Pt", &Reco_Muon_Trk_sumR05Pt_, &b_Reco_Muon_Trk_sumR05Pt);
    if (fChainM_["Reco"]->GetBranch("Reco_DiMuon_N"))                    fChainM_["Reco"]->SetBranchAddress("Reco_DiMuon_N", &Reco_DiMuon_N_, &b_Reco_DiMuon_N);
    if (fChainM_["Reco"]->GetBranch("Reco_DiMuon_Mom"))                  fChainM_["Reco"]->SetBranchAddress("Reco_DiMuon_Mom", &(TClonesArray_["Reco_DiMuon_Mom"]), &b_Reco_DiMuon_Mom);
    if (fChainM_["Reco"]->GetBranch("Reco_DiMuon_Charge"))               fChainM_["Reco"]->SetBranchAddress("Reco_DiMuon_Charge", &Reco_DiMuon_Charge_, &b_Reco_DiMuon_Charge);
    if (fChainM_["Reco"]->GetBranch("Reco_DiMuon_Muon1_Idx"))            fChainM_["Reco"]->SetBranchAddress("Reco_DiMuon_Muon1_Idx", &Reco_DiMuon_Muon1_Idx_, &b_Reco_DiMuon_Muon1_Idx);
    if (fChainM_["Reco"]->GetBranch("Reco_DiMuon_Muon2_Idx"))            fChainM_["Reco"]->SetBranchAddress("Reco_DiMuon_Muon2_Idx", &Reco_DiMuon_Muon2_Idx_, &b_Reco_DiMuon_Muon2_Idx);
    if (fChainM_["Reco"]->GetBranch("Reco_DiMuon_isCowBoy"))             fChainM_["Reco"]->SetBranchAddress("Reco_DiMuon_isCowBoy", &Reco_DiMuon_isCowBoy_, &b_Reco_DiMuon_isCowBoy);
    if (fChainM_["Reco"]->GetBranch("Reco_DiMuon_Vertex"))               fChainM_["Reco"]->SetBranchAddress("Reco_DiMuon_Vertex", &(TClonesArray_["Reco_DiMuon_Vertex"]), &b_Reco_DiMuon_Vertex);
    if (fChainM_["Reco"]->GetBranch("Reco_DiMuon_VtxProb"))              fChainM_["Reco"]->SetBranchAddress("Reco_DiMuon_VtxProb", &Reco_DiMuon_VtxProb_, &b_Reco_DiMuon_VtxProb);
    if (fChainM_["Reco"]->GetBranch("Reco_DiMuon_DCA"))                  fChainM_["Reco"]->SetBranchAddress("Reco_DiMuon_DCA", &Reco_DiMuon_DCA_, &b_Reco_DiMuon_DCA);
    if (fChainM_["Reco"]->GetBranch("Reco_DiMuon_MassErr"))              fChainM_["Reco"]->SetBranchAddress("Reco_DiMuon_MassErr", &Reco_DiMuon_MassErr_, &b_Reco_DiMuon_MassErr);
    // Set All Branches to Status 0
    fChainM_["Reco"]->SetBranchStatus("*",0);
  }

  // SET PF MUON BRANCHES
  if (fChainM_.count("PF")>0) {
    if (fChainM_["PF"]->GetBranch("PF_Candidate_isPU"))                  fChainM_["PF"]->SetBranchAddress("PF_Candidate_isPU", &PF_Candidate_isPU_, &b_PF_Candidate_isPU);
    if (fChainM_["PF"]->GetBranch("PF_Candidate_Id"))                    fChainM_["PF"]->SetBranchAddress("PF_Candidate_Id", &PF_Candidate_Id_, &b_PF_Candidate_Id);
    if (fChainM_["PF"]->GetBranch("PF_Candidate_Eta"))                   fChainM_["PF"]->SetBranchAddress("PF_Candidate_Eta", &PF_Candidate_Eta_, &b_PF_Candidate_Eta);
    if (fChainM_["PF"]->GetBranch("PF_Candidate_Phi"))                   fChainM_["PF"]->SetBranchAddress("PF_Candidate_Phi", &PF_Candidate_Phi_, &b_PF_Candidate_Phi);
    if (fChainM_["PF"]->GetBranch("PF_Candidate_Pt"))                    fChainM_["PF"]->SetBranchAddress("PF_Candidate_Pt", &PF_Candidate_Pt_, &b_PF_Candidate_Pt);
    if (fChainM_["PF"]->GetBranch("PF_Muon_N"))                          fChainM_["PF"]->SetBranchAddress("PF_Muon_N", &PF_Muon_N_, &b_PF_Muon_N);
    if (fChainM_["PF"]->GetBranch("PF_Muon_Mom"))                        fChainM_["PF"]->SetBranchAddress("PF_Muon_Mom", &(TClonesArray_["PF_Muon_Mom"]), &b_PF_Muon_Mom);
    if (fChainM_["PF"]->GetBranch("PF_Muon_Charge"))                     fChainM_["PF"]->SetBranchAddress("PF_Muon_Charge", &PF_Muon_Charge_, &b_PF_Muon_Charge);
    if (fChainM_["PF"]->GetBranch("PF_Muon_Gen_Idx"))                    fChainM_["PF"]->SetBranchAddress("PF_Muon_Gen_Idx", &PF_Muon_Gen_Idx_, &b_PF_Muon_Gen_Idx);
    if (fChainM_["PF"]->GetBranch("PF_Muon_Reco_Idx"))                   fChainM_["PF"]->SetBranchAddress("PF_Muon_Reco_Idx", &PF_Muon_Reco_Idx_, &b_PF_Muon_Reco_Idx);
    if (fChainM_["PF"]->GetBranch("PF_Muon_IsoPFR03"))                   fChainM_["PF"]->SetBranchAddress("PF_Muon_IsoPFR03", &PF_Muon_IsoPFR03_, &b_PF_Muon_IsoPFR03);
    if (fChainM_["PF"]->GetBranch("PF_Muon_IsoPFR03NoPUCorr"))           fChainM_["PF"]->SetBranchAddress("PF_Muon_IsoPFR03NoPUCorr", &PF_Muon_IsoPFR03NoPUCorr_, &b_PF_Muon_IsoPFR03NoPUCorr);
    if (fChainM_["PF"]->GetBranch("PF_Muon_IsoPFR04"))                   fChainM_["PF"]->SetBranchAddress("PF_Muon_IsoPFR04", &PF_Muon_IsoPFR04_, &b_PF_Muon_IsoPFR04);
    if (fChainM_["PF"]->GetBranch("PF_Muon_IsoPFR04NoPUCorr"))           fChainM_["PF"]->SetBranchAddress("PF_Muon_IsoPFR04NoPUCorr", &PF_Muon_IsoPFR04NoPUCorr_, &b_PF_Muon_IsoPFR04NoPUCorr);
    if (fChainM_["PF"]->GetBranch("PF_Muon_EM_Chg_sumR03Pt"))            fChainM_["PF"]->SetBranchAddress("PF_Muon_EM_Chg_sumR03Pt", &PF_Muon_EM_Chg_sumR03Pt_, &b_PF_Muon_EM_Chg_sumR03Pt);
    if (fChainM_["PF"]->GetBranch("PF_Muon_EM_Chg_sumR04Pt"))            fChainM_["PF"]->SetBranchAddress("PF_Muon_EM_Chg_sumR04Pt", &PF_Muon_EM_Chg_sumR04Pt_, &b_PF_Muon_EM_Chg_sumR04Pt);
    if (fChainM_["PF"]->GetBranch("PF_Muon_EM_Neu_sumR03Et"))            fChainM_["PF"]->SetBranchAddress("PF_Muon_EM_Neu_sumR03Et", &PF_Muon_EM_Neu_sumR03Et_, &b_PF_Muon_EM_Neu_sumR03Et);
    if (fChainM_["PF"]->GetBranch("PF_Muon_EM_Neu_sumR04Et"))            fChainM_["PF"]->SetBranchAddress("PF_Muon_EM_Neu_sumR04Et", &PF_Muon_EM_Neu_sumR04Et_, &b_PF_Muon_EM_Neu_sumR04Et);
    if (fChainM_["PF"]->GetBranch("PF_Muon_Had_Chg_sumR03Pt"))           fChainM_["PF"]->SetBranchAddress("PF_Muon_Had_Chg_sumR03Pt", &PF_Muon_Had_Chg_sumR03Pt_, &b_PF_Muon_Had_Chg_sumR03Pt);
    if (fChainM_["PF"]->GetBranch("PF_Muon_Had_Chg_sumR04Pt"))           fChainM_["PF"]->SetBranchAddress("PF_Muon_Had_Chg_sumR04Pt", &PF_Muon_Had_Chg_sumR04Pt_, &b_PF_Muon_Had_Chg_sumR04Pt);
    if (fChainM_["PF"]->GetBranch("PF_Muon_Had_Neu_sumR03Et"))           fChainM_["PF"]->SetBranchAddress("PF_Muon_Had_Neu_sumR03Et", &PF_Muon_Had_Neu_sumR03Et_, &b_PF_Muon_Had_Neu_sumR03Et);
    if (fChainM_["PF"]->GetBranch("PF_Muon_Had_Neu_sumR04Et"))           fChainM_["PF"]->SetBranchAddress("PF_Muon_Had_Neu_sumR04Et", &PF_Muon_Had_Neu_sumR04Et_, &b_PF_Muon_Had_Neu_sumR04Et);
    if (fChainM_["PF"]->GetBranch("PF_Muon_Had_PU_sumR03Pt"))            fChainM_["PF"]->SetBranchAddress("PF_Muon_Had_PU_sumR03Pt", &PF_Muon_Had_PU_sumR03Pt_, &b_PF_Muon_Had_PU_sumR03Pt);
    if (fChainM_["PF"]->GetBranch("PF_Muon_Had_PU_sumR04Pt"))            fChainM_["PF"]->SetBranchAddress("PF_Muon_Had_PU_sumR04Pt", &PF_Muon_Had_PU_sumR04Pt_, &b_PF_Muon_Had_PU_sumR04Pt);
    if (fChainM_["PF"]->GetBranch("PF_DiMuon_N"))                        fChainM_["PF"]->SetBranchAddress("PF_DiMuon_N", &PF_DiMuon_N_, &b_PF_DiMuon_N);
    if (fChainM_["PF"]->GetBranch("PF_DiMuon_Mom"))                      fChainM_["PF"]->SetBranchAddress("PF_DiMuon_Mom", &(TClonesArray_["PF_DiMuon_Mom"]), &b_PF_DiMuon_Mom);
    if (fChainM_["PF"]->GetBranch("PF_DiMuon_Charge"))                   fChainM_["PF"]->SetBranchAddress("PF_DiMuon_Charge", &PF_DiMuon_Charge_, &b_PF_DiMuon_Charge);
    if (fChainM_["PF"]->GetBranch("PF_DiMuon_Muon1_Idx"))                fChainM_["PF"]->SetBranchAddress("PF_DiMuon_Muon1_Idx", &PF_DiMuon_Muon1_Idx_, &b_PF_DiMuon_Muon1_Idx);
    if (fChainM_["PF"]->GetBranch("PF_DiMuon_Muon2_Idx"))                fChainM_["PF"]->SetBranchAddress("PF_DiMuon_Muon2_Idx", &PF_DiMuon_Muon2_Idx_, &b_PF_DiMuon_Muon2_Idx);
    if (fChainM_["PF"]->GetBranch("PF_DiMuon_Vertex"))                   fChainM_["PF"]->SetBranchAddress("PF_DiMuon_Vertex", &(TClonesArray_["PF_DiMuon_Vertex"]), &b_PF_DiMuon_Vertex);
    if (fChainM_["PF"]->GetBranch("PF_DiMuon_VtxProb"))                  fChainM_["PF"]->SetBranchAddress("PF_DiMuon_VtxProb", &PF_DiMuon_VtxProb_, &b_PF_DiMuon_VtxProb);
    if (fChainM_["PF"]->GetBranch("PF_DiMuon_DCA"))                      fChainM_["PF"]->SetBranchAddress("PF_DiMuon_DCA", &PF_DiMuon_DCA_, &b_PF_DiMuon_DCA);
    if (fChainM_["PF"]->GetBranch("PF_DiMuon_MassErr"))                  fChainM_["PF"]->SetBranchAddress("PF_DiMuon_MassErr", &PF_DiMuon_MassErr_, &b_PF_DiMuon_MassErr);
    if (fChainM_["PF"]->GetBranch("PF_MET_Mom"))                         fChainM_["PF"]->SetBranchAddress("PF_MET_Mom", &PF_MET_Mom_, &b_PF_MET_Mom);
    if (fChainM_["PF"]->GetBranch("PF_MuonMET_TransMom"))                fChainM_["PF"]->SetBranchAddress("PF_MuonMET_TransMom", &(TClonesArray_["PF_MuonMET_TransMom"]), &b_PF_MuonMET_TransMom);
    // Set All Branches to Status 0
    fChainM_["PF"]->SetBranchStatus("*",0);
  }

  // SET GEN MUON BRANCHES
  if (fChainM_.count("Gen")>0) {
    if (fChainM_["Gen"]->GetBranch("Gen_Particle_Mom"))                  fChainM_["Gen"]->SetBranchAddress("Gen_Particle_Mom", &(TClonesArray_["Gen_Particle_Mom"]), &b_Gen_Particle_Mom);
    if (fChainM_["Gen"]->GetBranch("Gen_Particle_PdgId"))                fChainM_["Gen"]->SetBranchAddress("Gen_Particle_PdgId", &Gen_Particle_PdgId_, &b_Gen_Particle_PdgId);
    if (fChainM_["Gen"]->GetBranch("Gen_Particle_Status"))               fChainM_["Gen"]->SetBranchAddress("Gen_Particle_Status", &Gen_Particle_Status_, &b_Gen_Particle_Status);
    if (fChainM_["Gen"]->GetBranch("Gen_Particle_Mother_Idx"))           fChainM_["Gen"]->SetBranchAddress("Gen_Particle_Mother_Idx", &Gen_Particle_Mother_Idx_, &b_Gen_Particle_Mother_Idx);
    if (fChainM_["Gen"]->GetBranch("Gen_Particle_Daughter_Idx"))         fChainM_["Gen"]->SetBranchAddress("Gen_Particle_Daughter_Idx", &Gen_Particle_Daughter_Idx_, &b_Gen_Particle_Daughter_Idx);
    if (fChainM_["Gen"]->GetBranch("Gen_Muon_N"))                        fChainM_["Gen"]->SetBranchAddress("Gen_Muon_N", &Gen_Muon_N_, &b_Gen_Muon_N);
    if (fChainM_["Gen"]->GetBranch("Gen_Muon_Mom"))                      fChainM_["Gen"]->SetBranchAddress("Gen_Muon_Mom", &(TClonesArray_["Gen_Muon_Mom"]), &b_Gen_Muon_Mom);
    if (fChainM_["Gen"]->GetBranch("Gen_Muon_Charge"))                   fChainM_["Gen"]->SetBranchAddress("Gen_Muon_Charge", &Gen_Muon_Charge_, &b_Gen_Muon_Charge);
    if (fChainM_["Gen"]->GetBranch("Gen_Muon_Particle_Idx"))             fChainM_["Gen"]->SetBranchAddress("Gen_Muon_Particle_Idx", &Gen_Muon_Particle_Idx_, &b_Gen_Muon_Particle_Idx);
    if (fChainM_["Gen"]->GetBranch("Gen_Muon_Reco_Idx"))                 fChainM_["Gen"]->SetBranchAddress("Gen_Muon_Reco_Idx", &Gen_Muon_Reco_Idx_, &b_Gen_Muon_Reco_Idx);
    if (fChainM_["Gen"]->GetBranch("Gen_Muon_PF_Idx"))                   fChainM_["Gen"]->SetBranchAddress("Gen_Muon_PF_Idx", &Gen_Muon_PF_Idx_, &b_Gen_Muon_PF_Idx);
    // Set All Branches to Status 0
    fChainM_["Gen"]->SetBranchStatus("*",0);
  }
}

void HiMuonTree::Clear(void)
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
  if (Event_Trig_Fired_)                 Event_Trig_Fired_->clear();
  if (Event_Trig_Presc_)                 Event_Trig_Presc_->clear();
  
  // CLEAR RECO MUON VARIABLES
  Reco_Muon_N_    = 0;
  Reco_DiMuon_N_  = 0;
  if (Reco_Muon_Charge_)                 Reco_Muon_Charge_->clear();
  if (Reco_Muon_Gen_Idx_)                Reco_Muon_Gen_Idx_->clear();
  if (Reco_Muon_PF_Idx_)                 Reco_Muon_PF_Idx_->clear();
  if (Pat_Muon_Trig_)                    Pat_Muon_Trig_->clear();
  if (Pat_Muon_dB_)                      Pat_Muon_dB_->clear();
  if (Pat_Muon_dBErr_)                   Pat_Muon_dBErr_->clear();
  if (Reco_Muon_isPF_)                   Reco_Muon_isPF_->clear();
  if (Reco_Muon_isGlobal_)               Reco_Muon_isGlobal_->clear();
  if (Reco_Muon_isTracker_)              Reco_Muon_isTracker_->clear();
  if (Reco_Muon_isStandAlone_)           Reco_Muon_isStandAlone_->clear();
  if (Reco_Muon_isLoose_)                Reco_Muon_isLoose_->clear();
  if (Reco_Muon_isMedium_)               Reco_Muon_isMedium_->clear();
  if (Reco_Muon_isHighPt_)               Reco_Muon_isHighPt_->clear();
  if (Reco_Muon_isSoft_)                 Reco_Muon_isSoft_->clear();
  if (Reco_Muon_isTight_)                Reco_Muon_isTight_->clear();
  if (Reco_Muon_isArbitrated_)           Reco_Muon_isArbitrated_->clear();
  if (Reco_Muon_TrackerArbitrated_)      Reco_Muon_TrackerArbitrated_->clear();
  if (Reco_Muon_GlobalPromptTight_)      Reco_Muon_GlobalPromptTight_->clear();
  if (Reco_Muon_TMLastStationLoose_)     Reco_Muon_TMLastStationLoose_->clear();
  if (Reco_Muon_TMLastStationTight_)     Reco_Muon_TMLastStationTight_->clear();
  if (Reco_Muon_TM2DCompatibilityLoose_) Reco_Muon_TM2DCompatibilityLoose_->clear();
  if (Reco_Muon_TM2DCompatibilityTight_) Reco_Muon_TM2DCompatibilityTight_->clear();
  if (Reco_Muon_TMOneStationLoose_)      Reco_Muon_TMOneStationLoose_->clear();
  if (Reco_Muon_TMOneStationTight_)      Reco_Muon_TMOneStationTight_->clear();
  if (Reco_Muon_GMTkChiCompatibility_)   Reco_Muon_GMTkChiCompatibility_->clear();
  if (Reco_Muon_GMStaChiCompatibility_)  Reco_Muon_GMStaChiCompatibility_->clear();
  if (Reco_Muon_GMTkKinkTight_)          Reco_Muon_GMTkKinkTight_->clear();
  if (Reco_Muon_TMLastStationAngLoose_)  Reco_Muon_TMLastStationAngLoose_->clear();
  if (Reco_Muon_TMLastStationAngTight_)  Reco_Muon_TMLastStationAngTight_->clear();
  if (Reco_Muon_TMOneStationAngLoose_)   Reco_Muon_TMOneStationAngLoose_->clear();
  if (Reco_Muon_TMOneStationAngTight_)   Reco_Muon_TMOneStationAngTight_->clear();
  if (Reco_Muon_MatchedStations_)        Reco_Muon_MatchedStations_->clear();
  if (Reco_Muon_Matches_)                Reco_Muon_Matches_->clear();
  if (Reco_Muon_SegmentComp_)            Reco_Muon_SegmentComp_->clear();
  if (Reco_Muon_Chi2Pos_)                Reco_Muon_Chi2Pos_->clear();
  if (Reco_Muon_TrkKink_)                Reco_Muon_TrkKink_->clear();
  if (Reco_Muon_InTrk_PtErr_)            Reco_Muon_InTrk_PtErr_->clear();
  if (Reco_Muon_InTrk_isHighPurity_)     Reco_Muon_InTrk_isHighPurity_->clear();
  if (Reco_Muon_InTrk_ValidHits_)        Reco_Muon_InTrk_ValidHits_->clear();
  if (Reco_Muon_InTrk_LostHits_)         Reco_Muon_InTrk_LostHits_->clear();
  if (Reco_Muon_InTrk_ValidPixHits_)     Reco_Muon_InTrk_ValidPixHits_->clear();
  if (Reco_Muon_InTrk_TrkLayers_)        Reco_Muon_InTrk_TrkLayers_->clear();
  if (Reco_Muon_InTrk_PixLayers_)        Reco_Muon_InTrk_PixLayers_->clear();
  if (Reco_Muon_InTrk_dXY_)              Reco_Muon_InTrk_dXY_->clear();
  if (Reco_Muon_InTrk_dXYErr_)           Reco_Muon_InTrk_dXYErr_->clear();
  if (Reco_Muon_InTrk_dZ_)               Reco_Muon_InTrk_dZ_->clear();
  if (Reco_Muon_InTrk_dZErr_)            Reco_Muon_InTrk_dZErr_->clear();
  if (Reco_Muon_InTrk_ValFrac_)          Reco_Muon_InTrk_ValFrac_->clear();
  if (Reco_Muon_InTrk_NormChi2_)         Reco_Muon_InTrk_NormChi2_->clear();
  if (Reco_Muon_GlbTrk_PtErr_)           Reco_Muon_GlbTrk_PtErr_->clear();
  if (Reco_Muon_GlbTrk_ValidMuonHits_)   Reco_Muon_GlbTrk_ValidMuonHits_->clear();
  if (Reco_Muon_GlbTrk_NormChi2_)        Reco_Muon_GlbTrk_NormChi2_->clear();
  if (Reco_Muon_BestTrk_Type_)           Reco_Muon_BestTrk_Type_->clear();
  if (Reco_Muon_BestTrk_PtErr_)          Reco_Muon_BestTrk_PtErr_->clear();
  if (Reco_Muon_BestTrk_dXY_)            Reco_Muon_BestTrk_dXY_->clear();
  if (Reco_Muon_BestTrk_dXYErr_)         Reco_Muon_BestTrk_dXYErr_->clear();
  if (Reco_Muon_BestTrk_dZ_)             Reco_Muon_BestTrk_dZ_->clear();
  if (Reco_Muon_BestTrk_dZErr_)          Reco_Muon_BestTrk_dZErr_->clear();
  if (Reco_Muon_IsoPFR03_)               Reco_Muon_IsoPFR03_->clear();
  if (Reco_Muon_IsoPFR03NoPUCorr_)       Reco_Muon_IsoPFR03NoPUCorr_->clear();
  if (Reco_Muon_IsoPFR04_)               Reco_Muon_IsoPFR04_->clear();
  if (Reco_Muon_IsoPFR04NoPUCorr_)       Reco_Muon_IsoPFR04NoPUCorr_->clear();
  if (Reco_Muon_EM_Chg_sumR03Pt_)        Reco_Muon_EM_Chg_sumR03Pt_->clear();
  if (Reco_Muon_EM_Chg_sumR04Pt_)        Reco_Muon_EM_Chg_sumR04Pt_->clear();
  if (Reco_Muon_EM_Neu_sumR03Et_)        Reco_Muon_EM_Neu_sumR03Et_->clear();
  if (Reco_Muon_EM_Neu_sumR04Et_)        Reco_Muon_EM_Neu_sumR04Et_->clear();
  if (Reco_Muon_Had_Chg_sumR03Pt_)       Reco_Muon_Had_Chg_sumR03Pt_->clear();
  if (Reco_Muon_Had_Chg_sumR04Pt_)       Reco_Muon_Had_Chg_sumR04Pt_->clear();
  if (Reco_Muon_Had_Neu_sumR03Et_)       Reco_Muon_Had_Neu_sumR03Et_->clear();
  if (Reco_Muon_Had_Neu_sumR04Et_)       Reco_Muon_Had_Neu_sumR04Et_->clear();
  if (Reco_Muon_Had_PU_sumR03Pt_)        Reco_Muon_Had_PU_sumR03Pt_->clear();
  if (Reco_Muon_Had_PU_sumR04Pt_)        Reco_Muon_Had_PU_sumR04Pt_->clear();
  if (Reco_Muon_IsoR03_)                 Reco_Muon_IsoR03_->clear();
  if (Reco_Muon_IsoR05_)                 Reco_Muon_IsoR05_->clear();
  if (Reco_Muon_Trk_sumR03Pt_)           Reco_Muon_Trk_sumR03Pt_->clear();
  if (Reco_Muon_Trk_sumR05Pt_)           Reco_Muon_Trk_sumR05Pt_->clear();
  if (Reco_DiMuon_Charge_)               Reco_DiMuon_Charge_->clear();
  if (Reco_DiMuon_Muon1_Idx_)            Reco_DiMuon_Muon1_Idx_->clear();
  if (Reco_DiMuon_Muon2_Idx_)            Reco_DiMuon_Muon2_Idx_->clear();
  if (Reco_DiMuon_isCowBoy_)             Reco_DiMuon_isCowBoy_->clear();
  if (Reco_DiMuon_VtxProb_)              Reco_DiMuon_VtxProb_->clear();
  if (Reco_DiMuon_DCA_)                  Reco_DiMuon_DCA_->clear();
  if (Reco_DiMuon_MassErr_)              Reco_DiMuon_MassErr_->clear();

  // CLEAR PF MUON VARIABLES
  PF_Muon_N_    = 0;
  PF_DiMuon_N_  = 0;
  if (PF_Candidate_isPU_)                PF_Candidate_isPU_->clear();
  if (PF_Candidate_Id_)                  PF_Candidate_Id_->clear();
  if (PF_Candidate_Eta_)                 PF_Candidate_Eta_->clear();
  if (PF_Candidate_Phi_)                 PF_Candidate_Phi_->clear();
  if (PF_Candidate_Pt_)                  PF_Candidate_Pt_->clear();
  if (PF_Muon_Charge_)                   PF_Muon_Charge_->clear();
  if (PF_Muon_Gen_Idx_)                  PF_Muon_Gen_Idx_->clear();
  if (PF_Muon_Reco_Idx_)                 PF_Muon_Reco_Idx_->clear();
  if (PF_Muon_IsoPFR03_)                 PF_Muon_IsoPFR03_->clear();
  if (PF_Muon_IsoPFR03NoPUCorr_)         PF_Muon_IsoPFR03NoPUCorr_->clear();
  if (PF_Muon_IsoPFR04_)                 PF_Muon_IsoPFR04_->clear();
  if (PF_Muon_IsoPFR04NoPUCorr_)         PF_Muon_IsoPFR04NoPUCorr_->clear();
  if (PF_Muon_EM_Chg_sumR03Pt_)          PF_Muon_EM_Chg_sumR03Pt_->clear();
  if (PF_Muon_EM_Chg_sumR04Pt_)          PF_Muon_EM_Chg_sumR04Pt_->clear();
  if (PF_Muon_EM_Neu_sumR03Et_)          PF_Muon_EM_Neu_sumR03Et_->clear();
  if (PF_Muon_EM_Neu_sumR04Et_)          PF_Muon_EM_Neu_sumR04Et_->clear();
  if (PF_Muon_Had_Chg_sumR03Pt_)         PF_Muon_Had_Chg_sumR03Pt_->clear();
  if (PF_Muon_Had_Chg_sumR04Pt_)         PF_Muon_Had_Chg_sumR04Pt_->clear();
  if (PF_Muon_Had_Neu_sumR03Et_)         PF_Muon_Had_Neu_sumR03Et_->clear();
  if (PF_Muon_Had_Neu_sumR04Et_)         PF_Muon_Had_Neu_sumR04Et_->clear();
  if (PF_Muon_Had_PU_sumR03Pt_)          PF_Muon_Had_PU_sumR03Pt_->clear();
  if (PF_Muon_Had_PU_sumR04Pt_)          PF_Muon_Had_PU_sumR04Pt_->clear();
  if (PF_DiMuon_Charge_)                 PF_DiMuon_Charge_->clear();
  if (PF_DiMuon_Muon1_Idx_)              PF_DiMuon_Muon1_Idx_->clear();
  if (PF_DiMuon_Muon2_Idx_)              PF_DiMuon_Muon2_Idx_->clear();
  if (PF_DiMuon_VtxProb_)                PF_DiMuon_VtxProb_->clear();
  if (PF_DiMuon_DCA_)                    PF_DiMuon_DCA_->clear();
  if (PF_DiMuon_MassErr_)                PF_DiMuon_MassErr_->clear();
  if (PF_MET_Mom_)                      *PF_MET_Mom_ = TVector2();

  // CLEAR GEN PARTICLE VARIABLES
  if (Gen_Particle_PdgId_)               Gen_Particle_PdgId_->clear();
  if (Gen_Particle_Status_)              Gen_Particle_Status_->clear();
  if (Gen_Particle_Mother_Idx_)          Gen_Particle_Mother_Idx_->clear();
  if (Gen_Particle_Daughter_Idx_)        Gen_Particle_Daughter_Idx_->clear();
  // CLEAR GEN MUON VARIABLES
  Gen_Muon_N_    = 0;
  if (Gen_Muon_Charge_)                  Gen_Muon_Charge_->clear();
  if (Gen_Muon_Particle_Idx_)                Gen_Muon_Particle_Idx_->clear();
  if (Gen_Muon_Reco_Idx_)                Gen_Muon_Reco_Idx_->clear();
  if (Gen_Muon_PF_Idx_)                  Gen_Muon_PF_Idx_->clear();
}

#endif
