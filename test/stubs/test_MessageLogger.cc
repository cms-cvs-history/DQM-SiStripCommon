#include "DQM/SiStripCommon/test/stubs/test_MessageLogger.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "DataFormats/SiStripCommon/interface/SiStripConstants.h"
#include <iostream>
#include <sstream>

using namespace std;
using namespace sistrip;

// -----------------------------------------------------------------------------
// 
void test_MessageLogger::analyze( const edm::Event& event,
				  const edm::EventSetup& setup ) {
  
  LogDebug("Anything")
    << "Starting to analyzing run/event: "
    << event.id().run() << "/"
    << event.id().event();
  
  LogDebug(mlRawToDigi_) << "get this 1";
  LogTrace(mlRawToDigi_) << "get this 2";
  edm::LogInfo(mlRawToDigi_) << "get this 3" << endl;
  edm::LogVerbatim(mlRawToDigi_) << "get this 4";
  stringstream ss; ss << "get this 5";
  edm::LogVerbatim(mlRawToDigi_) << ss.str();
  edm::LogVerbatim(mlRawToDigi_) << "@SUB=MethodName get this 6";
  edm::LogVerbatim(mlRawToDigi_) << "@SUB=MethodName" << " get this 7";
  edm::LogVerbatim(mlRawToDigi_) << "@SUB=MethodName" << " get this 8" << "\n";
  
  LogDebug("Anything")
    << "Finished analyzing run/event: "
    << event.id().run() << "/"
    << event.id().event();  

}
