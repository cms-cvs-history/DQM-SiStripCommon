#ifndef DQM_SiStripCommon_test_ParameterSet_H
#define DQM_SiStripCommon_test_ParameterSet_H

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include <string>

/**
   @class test_ParameterSet 
   @brief test class
*/
class test_ParameterSet : public edm::EDAnalyzer {
  
 public:
  
  test_ParameterSet( const edm::ParameterSet& );
  ~test_ParameterSet() {;}
  
  void beginJob( edm::EventSetup const& );
  void analyze( const edm::Event&, const edm::EventSetup& ) {;}
  void endJob() {;}

 private:

  std::string path_;
  int instance_;
  
};

#endif // DQM_SiStripCommon_test_ParameterSet_H

