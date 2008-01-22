#include "DQM/SiStripCommon/test/plugins/test_ParameterSet.h"
#include "DataFormats/SiStripCommon/interface/SiStripConstants.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ParameterSet/interface/MakeParameterSets.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;
using namespace sistrip;

// -----------------------------------------------------------------------------
// 
test_ParameterSet::test_ParameterSet( const edm::ParameterSet& pset ) 
  : path_( pset.getUntrackedParameter<string>("PathToCfg","") ),
    instance_( pset.getUntrackedParameter<int>("Instance",-1) )
{
  
  // Set path
  std::string cmssw_base = "CMSSW_BASE";
  if ( getenv(cmssw_base.c_str()) ) { cmssw_base = getenv(cmssw_base.c_str()); }
  path_ = cmssw_base + "/src/" + path_;

  // Check path
  if ( ifstream( path_.c_str() ).fail() ) {
    edm::LogWarning(mlTest_)
      << "[test_ParameterSet::" << __func__ << "]"
      << " Cannot find .cfg file at: " << path_;
    path_.clear();
  } else {
    LogTrace(mlTest_)
      << "[test_ParameterSet::" << __func__ << "]"
      << " Found .cfg file at: " << path_;
  }

}


// -----------------------------------------------------------------------------
// 
void test_ParameterSet::beginJob( const edm::EventSetup& setup ) {
  
  // Read .cfg file
  std::stringstream config; 
  if ( !path_.empty() ) {
    ifstream in;
    in.open( path_.c_str() );
    if ( in.is_open() ) {
      while ( !in.eof() ) {
	std::string data;
	getline(in,data);
	config << data << "\n"; 
      }
      in.close();
      std::stringstream ss;
    }
  }
  
  // Modify .cfg string 

  std::string configuration = config.str();
  std::string::size_type start = configuration.find("FUInstance");
  if ( start != std::string::npos ) {
    std::string::size_type size = std::string("FUInstance").size() + std::string(" + ").size() + 5;
    std::string substr = configuration.substr( start, size );
    std::string::size_type pos = substr.find( "-1" );
    if ( pos != std::string::npos ) {
      std::stringstream ss;
      ss << std::setw(3) << std::setfill(' ') << instance_;
      configuration.replace( start+pos, 2, ss.str() ); 
    }
  } 
  
  std::stringstream ss;
  ss << "[test_ParameterSet::" << __func__ << "]"
     << " Configuration string is: " << std::endl
     << configuration;
  LogTrace(mlTest_) << ss.str();
  
  boost::shared_ptr<edm::ParameterSet> pset;
  boost::shared_ptr< vector<edm::ParameterSet> > psets;
  makeParameterSets( configuration, pset, psets );

  LogTrace(mlTest_)
    << "[test_ParameterSet::" << __func__ << "]"
    << " PSet is: " << std::endl
    << *pset;

  std::stringstream sss;
  sss << "[test_ParameterSet::" << __func__ << "]"
      << " PSets are: " << std::endl;
  vector<edm::ParameterSet>::const_iterator iter = psets->begin();
  for ( ; iter != psets->end(); iter++  ) {
    sss << *iter << std::endl;
  }
  LogTrace(mlTest_) << sss.str();

//   boost::shared_ptr<edm::ParameterSet> pset1;
//   boost::shared_ptr< vector<edm::ParameterSet> > psets1;
//   makeParameterSets( pset->toString(), pset1, psets1 );

//   LogTrace(mlTest_)
//     << "[test_ParameterSet::" << __func__ << "]"
//     << " PSet1 is: " << std::endl
//     << *pset1;


//   LogTrace(mlTest_)
//     << "[test_ParameterSet::" << __func__ << "]"
//     << " read_whole_file is: " << std::endl
//     << edm::pset::read_whole_file(path_);
  
//   ParseResults pr = edm::pset::parse(configuration.c_str());
//   if(!pr)
//     {
//       cerr << "Null output from parser" << endl;
//       return;
//     }
//   copy(pr->begin(),
//        pr->end(),
//        ostream_iterator<edm::pset::NodePtr>(cout,"\n"));
  
//   edm::ProcessDesc b(configuration.c_str());
//   boost::shared_ptr<edm::ParameterSet> test = b.getProcessPSet();
//   cout << test->toString() << endl;


}
