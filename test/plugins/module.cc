#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_SEAL_MODULE();

#include "DQM/SiStripCommon/test/plugins/test_MessageLogger.h"
DEFINE_ANOTHER_FWK_MODULE(test_MessageLogger);

#include "DQM/SiStripCommon/test/plugins/test_ParameterSet.h"
DEFINE_ANOTHER_FWK_MODULE(test_ParameterSet);
