#ifndef DQM_SiStripCommon_SiStripHistoNamingScheme_H
#define DQM_SiStripCommon_SiStripHistoNamingScheme_H

#include "DataFormats/SiStripCommon/interface/SiStripConstants.h"
#include "DataFormats/SiStripCommon/interface/SiStripEnumeratedTypes.h"
#include "DQM/SiStripCommon/interface/SiStripConstants.h"
#include "DQM/SiStripCommon/interface/SiStripEnumeratedTypes.h"
#include "boost/cstdint.hpp"
#include <string>

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
    std::string          extraInfo_;
  };
  
  /** Simple struct to hold control path parameters. */
  class ControlPath {
  public:
    uint16_t fecCrate_;
    uint16_t fecSlot_;
    uint16_t fecRing_;
    uint16_t ccuAddr_;
    uint16_t ccuChan_;
    ControlPath() : 
      fecCrate_(sistrip::invalid_), 
      fecSlot_(sistrip::invalid_), 
      fecRing_(sistrip::invalid_), 
      ccuAddr_(sistrip::invalid_), 
      ccuChan_(sistrip::invalid_) {;} 
  };
  
  // ----- METHODS RETURNING SOME GENERIC STRINGS AND ENUMS -----
  
  static std::string view( const sistrip::View& );
  static std::string task( const sistrip::Task& );
  static std::string contents( const sistrip::Contents& );
  static std::string keyType( const sistrip::KeyType& );
  static std::string granularity( const sistrip::Granularity& );
  
  static sistrip::View view( const std::string& directory );
  static sistrip::Task task( const std::string& task );
  static sistrip::Contents contents( const std::string& contents );
  static sistrip::KeyType keyType( const std::string& key_type );
  static sistrip::Granularity granularity( const std::string& granularity );
  
  // ----- FORMULATION OF DIRECTORY PATHS -----

  /** Returns directory path in the form of a string, based on control
      params (FEC crate, slot and ring, CCU address and channel). */ 
  static std::string controlPath( uint16_t fec_crate = sistrip::invalid_, 
				  uint16_t fec_slot  = sistrip::invalid_, 
				  uint16_t fec_ring  = sistrip::invalid_, 
				  uint16_t ccu_addr  = sistrip::invalid_, 
				  uint16_t ccu_chan  = sistrip::invalid_ );

  /** Returns directory path in the form of a string, based on control
      path (FEC crate, slot and ring, CCU address and channel). */ 
  inline static std::string controlPath( const ControlPath& );
  
  /** Returns control parameters in the form of a "ControlPath" struct,
      based on directory path string of the form
      ControlView/FecCrateA/FecSlotA/FecRingC/CcuAddrD/CcuChanE/. */
  static const ControlPath& controlPath( const std::string& path );
  
  /** Returns directory path in the form of a string, based on readout
      parameters (FED id and channel). */ 
  static std::string readoutPath( uint16_t fed_id = sistrip::invalid_, 
				  uint16_t fed_ch = sistrip::invalid_ );
  
  /** Returns readout parameters in the form of a pair (FED
      id/channel), based on directory path string of the form
      ReadoutView/FedIdX/FedChannelY/. */
  static std::pair<uint16_t,uint16_t> readoutPath( const std::string& directory );
  
  // ----- FORMULATION OF HISTOGRAM TITLES -----
  
  /** Contructs histogram name based on a general histogram name,
      histogram contents, a histogram key and a channel id. */
  inline static std::string histoTitle( HistoTitle title );
  
  /** Contructs histogram name based on a general histogram name,
      histogram contents, a histogram key and a channel id. */
  static std::string histoTitle( sistrip::Task        task,
				 sistrip::Contents    contents   = sistrip::COMBINED, 
				 sistrip::KeyType     key_type   = sistrip::NO_KEY, 
				 uint32_t             key_value  = 0, 
				 sistrip::Granularity granarity  = sistrip::MODULE,
				 uint16_t             channel    = 0,
				 std::string          extra_info = "" );
  
  /** Extracts various parameters from histogram name and returns the
      values in the form of a HistoTitle struct. */
  static HistoTitle histoTitle( std::string histo_title );  
  
};

// ---------- inline methods ----------

std::string SiStripHistoNamingScheme::histoTitle( SiStripHistoNamingScheme::HistoTitle title ) {
  return histoTitle( title.task_, 
		     title.contents_, 
		     title.keyType_, 
		     title.keyValue_, 
		     title.granularity_, 
		     title.channel_, 
		     title.extraInfo_ );
}
  
std::string SiStripHistoNamingScheme::controlPath( const ControlPath& path ) {
  return controlPath( path.fecCrate_,
		      path.fecSlot_,
		      path.fecRing_,
		      path.ccuAddr_,
		      path.ccuChan_ );
}

#endif // DQM_SiStripCommon_SiStripHistoNamingScheme_H


