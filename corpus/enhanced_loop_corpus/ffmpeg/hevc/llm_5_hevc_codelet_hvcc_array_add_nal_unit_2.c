#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HVCCNALUnitArray {
    uint8_t array_completeness;
    uint8_t NAL_unit_type;
    uint16_t numNalus;
    uint16_t *nalUnitLength;
    uint8_t **nalUnit;
} HVCCNALUnitArray;

typedef struct HEVCDecoderConfigurationRecord {
    uint8_t configurationVersion;
    uint8_t general_profile_space;
    uint8_t general_tier_flag;
    uint8_t general_profile_idc;
    uint32_t general_profile_compatibility_flags;
    uint64_t general_constraint_indicator_flags;
    uint8_t general_level_idc;
    uint16_t min_spatial_segmentation_idc;
    uint8_t parallelismType;
    uint8_t chromaFormat;
    uint8_t bitDepthLumaMinus8;
    uint8_t bitDepthChromaMinus8;
    uint16_t avgFrameRate;
    uint8_t constantFrameRate;
    uint8_t numTemporalLayers;
    uint8_t temporalIdNested;
    uint8_t lengthSizeMinusOne;
    uint8_t numOfArrays;
    HVCCNALUnitArray *array;
} HEVCDecoderConfigurationRecord;

extern uint8_t nal_type;
extern HEVCDecoderConfigurationRecord *hvcc;
extern uint8_t _usr_index;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    uint8_t found = 0;
    for (index = 0; index < hvcc->numOfArrays && !found; index++) {
        found = (hvcc->array[index].NAL_unit_type == nal_type);
        if (!found) {
            index++;
        } else {
            index--; // Compensate for increment in matching case to keep correct index
        }
    }
}
