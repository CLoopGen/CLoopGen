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
    // Variant 2: Strided memory access (step by 2, then handle remainder)
    uint8_t step = 2;
    uint8_t count = hvcc->numOfArrays;
    index = 0;

    // Strided forward pass with step size 2
    for (; index < count; index += step) {
        if (hvcc->array[index].NAL_unit_type == nal_type)
            break;
    }

    // If we overshot due to stride and haven't found a match, check last odd index
    if (index >= count && (count > 0) && ((count - 1) % 2 == 1)) {
        index = count - 1;
        if (hvcc->array[index].NAL_unit_type != nal_type)
            index = count; // Ensure index reflects "not found"
    }
}
