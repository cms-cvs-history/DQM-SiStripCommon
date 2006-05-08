#ifndef DQM_SiStripCommon_SiStripHistoNamingScheme_H
#define DQM_SiStripCommon_SiStripHistoNamingScheme_H

#include "DQM/SiStripCommon/interface/SiStripHistoNamingConstants.h"
#include "boost/cstdint.hpp"
#include <string>

using namespace std;

class SiStripHistoNamingScheme {
  
 public:

  // ----- STRUCTS AND ENUMS -----

  /** Simple struct to hold components of histogram title. */
  struct HistoTitle {
    sistrip::Task        task_;
    sistrip::Contents    contents_;
    sistrip::KeyType     keyType_;
    uint32_t             keyValue_;
    sistrip::Granularity granularity_;
    uint16_t             channel_;
    string               extraInfo_;
  };
  
  /** Simple struct to hold control path parameters. */
  struct ControlPath {
    uint16_t fecCrate_;
    uint16_t fecSlot_;
    uint16_t fecRing_;
    uint16_t ccuAddr_;
    uint16_t ccuChan_;
  };
  
  // ----- METHODS RETURNING SOME GENERIC STRINGS AND CONSTANTS -----

  sistrip::View view( string directory );

  // ----- FORMULATION OF DIRECTORY PATHS -----

  /** Returns directory path in the form of a string, based on control
      params (FEC crate, slot and ring, CCU address and channel). */ 
  static string controlPath( uint16_t fec_crate = sistrip::all_, 
			     uint16_t fec_slot  = sistrip::all_, 
			     uint16_t fec_ring  = sistrip::all_, 
			     uint16_t ccu_addr  = sistrip::all_, 
			     uint16_t ccu_chan  = sistrip::all_ );

  /** Returns control parameters in the form of a "ControlPath" struct,
      based on directory path string of the form
      ControlView/FecCrateA/FecSlotA/FecRingC/CcuAddrD/CcuChanE/. */
  static ControlPath controlPath( string path );
  
  /** Returns directory path in the form of a string, based on readout
      parameters (FED id and channel). */ 
  static string readoutPath( uint16_t fed_id = sistrip::all_, 
			     uint16_t fed_channel = sistrip::all_ );

  /** Returns readout parameters in the form of a pair (FED
      id/channel), based on directory path string of the form
      ReadoutView/FedIdX/FedChannelY/. */
  static pair<uint16_t,uint16_t> readoutPath( string path ) { return pair<uint16_t,uint16_t>(0,0); } //@@ NO IMPLEMENTATION YET!
  
  // ----- FORMULATION OF HISTOGRAM TITLES -----

  /** Contructs histogram name based on a general histogram name,
      histogram contents, a histogram key and a channel id. */
  static string histoTitle( sistrip::Task        task,
			    sistrip::Contents    contents   = sistrip::COMBINED, 
			    sistrip::KeyType     key_type   = sistrip::NO_KEY, 
			    uint32_t             key_value  = 0, 
			    sistrip::Granularity granarity  = sistrip::MODULE,
			    uint16_t             channel    = 0,
			    string               extra_info = "" );

  /** Extracts various parameters from histogram name and returns the
      values in the form of a HistoTitle struct. */
  static HistoTitle histoTitle( string histo_title );  

  static string task( sistrip::Task task );
  static string contents( sistrip::Contents contents );
  static string keyType( sistrip::KeyType key_type );
  static string granularity( sistrip::Granularity Granularity );
  static sistrip::Task task( string task );
  static sistrip::Contents contents( string contents );
  static sistrip::KeyType keyType( string key_type );
  static sistrip::Granularity granularity( string granularity );

};

#endif // DQM_SiStripCommon_SiStripHistoNamingScheme_H


