#ifndef NEUTON_MODEL_MODEL_H
#define NEUTON_MODEL_MODEL_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Model info */
#define NEUTON_MODEL_HEADER_VERSION 3
#define NEUTON_MODEL_QLEVEL 8
#define NEUTON_MODEL_FLOAT_SUPPORT 0
#define NEUTON_MODEL_TASK_TYPE 0  // multiclass classification
#define NEUTON_MODEL_NEURONS_COUNT 24
#define NEUTON_MODEL_WEIGHTS_COUNT 149
#define NEUTON_MODEL_INPUTS_COUNT 638
#define NEUTON_MODEL_INPUTS_COUNT_ORIGINAL 3
#define NEUTON_MODEL_INPUT_LIMITS_COUNT 638
#define NEUTON_MODEL_OUTPUTS_COUNT 4
#define NEUTON_MODEL_LOG_SCALE_OUTPUTS 0
#define NEUTON_MODEL_HAS_CLASSES_RATIO 0
#define NEUTON_MODEL_HAS_NEGPOS_RATIO 0

/* Preprocessing */
#define NEUTON_PREPROCESSING_ENABLED 1
#define NEUTON_MODEL_WINDOW_SIZE 200
#define NEUTON_DROP_ORIGINAL_FEATURES 0
#define NEUTON_BITMASK_ENABLED 1
#define NEUTON_INPUTS_IS_INTEGER 0
#define NEUTON_MODEL_SA_PRECISION 24

/* Types */
typedef float input_t;
typedef float extracted_feature_t;
typedef uint8_t coeff_t;
typedef int8_t weight_t;
typedef int32_t acc_signed_t;
typedef uint32_t acc_unsigned_t;
typedef uint16_t sources_size_t;
typedef uint8_t weights_size_t;
typedef uint8_t neurons_size_t;

/* Scaling */
static const input_t modelInputScaleMin[] = { -39.220001, -39.220001, -39.220001 };
static const input_t modelInputScaleMax[] = { 39.220001, 39.220001, 39.220001 };

static const extracted_feature_t extractedFeaturesScaleMin[] = {
	0.069765627, 0.0011718571, -26.055687, -7.8099999, -39.220001, 1.0003772,
	0.0003609375, 0.018998355, -5.1252894, -1.720486, 1, 0, 0, 0.101875, 0.01343751,
	-9.751852, -2.3699999, -39.220001, 1.0003772, 0.00053804001, 0.02319569,
	-5.1598597, -1.7571391, 1, 0, 0.12281322, 0.0081253052, -3.5886014, 2.72,
	-39.220001, 1.0003772, 0.00075009483, 0.027387859, -3.6018598, -1.6228197,
	1, 1, 0 };
static const extracted_feature_t extractedFeaturesScaleMax[] = {
	75.974686, 17.560146, 9.4387999, 39.220001, 8.9399996, 1.0322464, 341.38684,
	18.476656, 4.6811604, 39.27594, 90, 45, 45, 100.33094, 59.793434, 5.381649,
	39.220001, 0.050000001, 1.031564, 1152.7917, 33.952785, 4.3883543, 44.854622,
	44, 44, 96.956253, 52.851562, 11.468846, 39.220001, 9.3500004, 1.0423181,
	884.10352, 29.733879, 6.4205904, 68.018753, 120, 60, 60 };

/* Limits */
static const uint8_t modelUsedInputsMask[] = {
	0x81, 0x03, 0x00, 0x04, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x04, 0xa0,
	0x04, 0x40, 0x09, 0x00, 0x40, 0x54, 0x00, 0x40, 0x01, 0x00, 0x0c, 0xd0,
	0xb8, 0x00, 0x00, 0x00, 0x40, 0x01, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00,
	0x00, 0x08, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xc0,
	0x22, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0x0c, 0x02, 0x00, 0x01, 0x20,
	0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0xa0, 0x08, 0x02, 0xc0,
	0x01, 0x18, 0x81, 0x6c, 0x5b, 0x43, 0x80, 0x25 };

/* Structure */
static const weight_t modelWeights[] = {
	-101, 53, 120, -128, 108, 17, -104, 85, 123, 125, -62, -86, 86, -47, -69,
	-126, 124, 65, 61, -2, -65, -128, -65, -2, 125, 34, 35, 125, -72, -45,
	-115, 77, -90, -61, 14, -127, -28, -128, 46, -103, 121, 92, 95, -127, -128,
	6, -124, 125, 126, -128, -124, 46, -87, -82, -115, 76, 58, 79, -122, 47,
	-35, -105, -8, 119, 57, -54, -122, -73, 124, 19, 19, 124, 76, -122, -50,
	115, -42, 124, -98, 73, -126, 47, -38, 125, -118, 105, -40, -76, -11, 3,
	124, -121, -82, 105, 32, 32, -100, 26, 66, -87, -37, -69, 80, 117, -66,
	117, 120, -111, 21, 31, -99, -94, -127, 122, 125, -128, 9, 36, 22, -39,
	-109, 123, 45, 55, 125, -112, -83, 48, 5, -128, -37, -128, -128, -128,
	74, 126, -16, 47, 63, -26, -84, -111, -128, 125, -128, 29, -128, 114, -2 };

static const sources_size_t modelLinks[] = {
	385, 608, 611, 614, 631, 638, 0, 178, 190, 199, 588, 638, 140, 555, 617,
	632, 637, 638, 7, 443, 603, 612, 622, 638, 93, 98, 112, 158, 532, 616,
	638, 142, 603, 611, 632, 634, 638, 2, 4, 82, 382, 605, 638, 1, 230, 299,
	576, 612, 638, 2, 7, 638, 188, 196, 602, 608, 614, 638, 5, 9, 179, 191,
	561, 634, 638, 2, 9, 115, 195, 551, 638, 5, 138, 383, 477, 587, 638, 54,
	312, 352, 389, 531, 638, 26, 134, 232, 262, 549, 638, 8, 160, 575, 599,
	634, 638, 415, 442, 464, 592, 606, 638, 3, 4, 9, 11, 13, 15, 16, 638, 0,
	1, 2, 3, 9, 13, 261, 638, 4, 483, 551, 574, 609, 638, 13, 95, 484, 487,
	588, 638, 1, 6, 12, 18, 20, 638, 110, 197, 431, 449, 480, 603, 638, 0,
	5, 10, 14, 19, 22, 638 };

static const weights_size_t modelIntLinksBoundaries[] = {
	0, 6, 12, 18, 24, 31, 39, 44, 51, 52, 60, 66, 72, 77, 83, 89, 95, 108,
	115, 118, 124, 134, 135, 148 };
static const weights_size_t modelExtLinksBoundaries[] = {
	6, 12, 18, 24, 31, 37, 43, 49, 52, 58, 65, 71, 77, 83, 89, 95, 101, 109,
	117, 123, 129, 135, 142, 149 };

static const coeff_t modelFuncCoeffs[] = {
	160, 160, 100, 133, 148, 157, 144, 158, 72, 156, 150, 143, 160, 157, 105,
	156, 149, 101, 1, 152, 157, 156, 158, 160 };
static const uint8_t modelFuncTypes[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

static const neurons_size_t modelOutputNeurons[] = { 23, 21, 8, 17 };

#ifdef __cplusplus
}
#endif

#endif // NEUTON_MODEL_MODEL_H

