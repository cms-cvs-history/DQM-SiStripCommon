#ifndef DQM_SiStripCommon_test_MessageLogger_H
#define DQM_SiStripCommon_test_MessageLogger_H

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

/**
   @class test_MessageLogger 
   @brief Simple class that analyzes Digis produced by RawToDigi unpacker
*/
class test_MessageLogger : public edm::EDAnalyzer {
  
 public:
  
  test_MessageLogger( const edm::ParameterSet& ) {;}
  ~test_MessageLogger() {;}
  
  void beginJob( edm::EventSetup const& ) {;}
  void analyze( const edm::Event&, const edm::EventSetup& );
  void endJob() {;}
  
};

#endif // DQM_SiStripCommon_test_MessageLogger_H

