#include "FWCore/Framework/interface/MakerMacros.h"
#include "PluginManager/ModuleDef.h"
DEFINE_SEAL_MODULE();

#include "DQM/SiStripCommon/test/stubs/test_MessageLogger.h"
DEFINE_ANOTHER_FWK_MODULE(test_MessageLogger);
