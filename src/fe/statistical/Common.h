#ifndef NEUTON_FE_STATISTICAL_COMMON_H
#define NEUTON_FE_STATISTICAL_COMMON_H

#include <stdint.h>
#include <stddef.h>
#include <string.h>

// code for python lib does not have dsp_config.h/model.h
#ifndef PYTHON_LIB
#include "../../model/model.h"

	#if (NEUTON_PREPROCESSING_ENABLED == 1)
	#include "../../model/dsp_config.h"
	#endif

#endif

#ifdef __cplusplus
extern "C" {
#endif

#define BITMASK_MEAN					(uint16_t)(1)<<0
#define BITMASK_MOMENT_2				(uint16_t)(1)<<1
#define BITMASK_MOMENT_3				(uint16_t)(1)<<2
#define BITMASK_MOMENT_4				(uint16_t)(1)<<3
#define BITMASK_ZERO_CROSSING			(uint16_t)(1)<<4
#define BITMASK_MIN						(uint16_t)(1)<<5
#define BITMASK_MAX						(uint16_t)(1)<<6
#define BITMASK_MOOVING_AVERAGE			(uint16_t)(1)<<7
#define BITMASK_AMP_HIGH_FREQUENCY_P2P	(uint16_t)(1)<<8
#define BITMASK_AMP_LOW_FREQUENCY_P2P	(uint16_t)(1)<<9
#define BITMASK_FFT_ANY					(uint16_t)(1)<<10

#define FHT_RESULTS_NUMBER	3
	
enum Moments
{
	MOMENT_2 = 0,
	MOMENT_3,
	MOMENT_4,

	MOM_COUNT
};

// inpute params for features. Using special enum (not ExtractedFeatures), because most features
// do not have any inpute params.
typedef enum _extracted_features_params
{
	// one common param for all. If user provides more, then 1, the last one is taken (in current version of code)
	EF_PARAM_STAT_MEAN_CROSSING = 0,
	/*EF_PARAM_STAT_NEGATIVE_MEAN_CROSSING,
	EF_PARAM_STAT_POSITIVE_MEAN_CROSSING,*/

	// one common param for all. If user provides more, then 1, the last one is taken (in current version of code)	
	EF_PARAM_AMP_FREQUENCY_P2P,
	/*EF_PARAM_AMP_HIGH_FREQUENCY_P2P,
	EF_PARAM_AMP_LOW_FREQUENCY_P2P,*/

	EF_PARAM_COUNT
	
} extracted_features_params;

typedef uint16_t calc_bit_mask_t;

///
/// \brief Structure descibing FHT block
///
typedef struct _neuton_dsp_fht_instance
{
	///
	/// \brief FHT sin() table (elemnts count is @fftWindowSize / 4). Initialize with @fftSinTable
	///
	const void* sinTable;

	///
	/// \brief FHT tg() table (elemnts count is @fftWindowSize / 4). Initialize with @fftTgTable
	///
	const void* tgTable;

	///
	/// \brief FHT reordering array (elemnts count is @fftWindowSize). Initialize with @fftReversedBitIndexArray
	///
	const uint16_t* reversedBitIndexArray;

	///
	/// \brief FHT Window buffer array (elemnts count is @fftWindowSize). Initialize with @fftWindow
	///
	void* windowArray;

	///
	/// \brief FHT window size (n elements)
	///
	uint16_t fhtWindowSize;

	///
	/// \brief Cached value of log2(@n_fht)
	///
	uint16_t logN;
	
} neuton_dsp_fht_instance;

///
/// \brief Get element count of input normalization array
/// \param p_ExtractedFeatures - array of extracted features for axis
/// \param p_ExtractedFeaturesCount - number of elements in array
/// \param p_ColIdx - Current axis index
/// \param p_calc_bit_mask_t - Output param. Populated mask with features, that mast be calculated in Stat Alg.
///
void PopulateFeatureMask(
	const uint16_t* p_ExtractedFeatures,
	uint16_t p_ExtractedFeaturesCount,
	uint16_t p_ColIdx,
	calc_bit_mask_t* p_calc_bit_mask_t);

///
/// \brief Gets ptr to global array with input params for extracted features (data in ptr must stay unchanged!)
/// \param axisIdx - Index of column (index in global array of dsp_axis_info type)
/// \param paramToGet - Param to get. If feature suppose to has more,
/// then one int32_t, the second can be located (ret_ptr + 1)
///
const int32_t* GetFeatureInputParams(uint16_t axisIdx, extracted_features_params paramToGet);

///
/// \brief Gets ptr to cached neuton_dsp_fht_instance structure
/// \param axisIdx - Index of column (index in global array of dsp_axis_info type)
/// \param instanceToGet - Param to get.
///
void GetFhtInstanceFromAxisCache(uint16_t axisIdx, neuton_dsp_fht_instance const** instanceToGet);
	
#if (NEUTON_PREPROCESSING_ENABLED == 1)

extern const uint16_t featuresCalculationRequestedMask[];
	
// Information for every axis, that is used in DSP. Most field are cached.	
typedef struct _dsp_axis_info
{
	// Fht instance for axis. Used if Fht Extracted Feature is required for axis
	// Data is declared (generated) in dsp_config.h
	neuton_dsp_fht_instance fhtInstance;
	
	// Index to each param for current axis in global param array modelExtractedFeaturesParams
	// If extracted parameter has more, then one input param, second and other parameters
	// can be obtained by
	// &modelExtractedFeaturesParams[efParamIdx[EF_PARAM_STAT_MEAN_CROSSING]] + 1
	
	uint16_t efParamIdx[EF_PARAM_COUNT];

	// Bit mask of all features, that must be preCalculated (moved here due optimization)
	// 0 == not initialized
	calc_bit_mask_t calcBitMask;
	
} dsp_axis_info;

///
/// \brief Initializes Dsp code (library). Must be called once before any calls of DSP functions.
///
void dsp_init_lib();

#endif  //#if (NEUTON_PREPROCESSING_ENABLED == 1)
	
#ifdef __cplusplus
}
#endif

#endif // NEUTON_FE_STATISTICAL_COMMON_H
