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

uint8_t nal_type;
HEVCDecoderConfigurationRecord *hvcc;
uint8_t _usr_index;

#define index _usr_index

static uint16_t* create_uint16_array(size_t size) {
    uint16_t *arr = malloc(size * sizeof(uint16_t));
    for (size_t i = 0; i < size; i++) {
        arr[i] = 1024;
    }
    return arr;
}

static uint8_t** create_uint8_matrix(size_t rows, size_t cols) {
    uint8_t **matrix = malloc(rows * sizeof(uint8_t*));
    for (size_t i = 0; i < rows; i++) {
        matrix[i] = malloc(cols);
        for (size_t j = 0; j < cols; j++) {
            matrix[i][j] = (uint8_t)(i + j);
        }
    }
    return matrix;
}

static HVCCNALUnitArray* create_hvcc_array(size_t num_arrays, uint8_t target_type) {
    HVCCNALUnitArray *arrays = malloc(num_arrays * sizeof(HVCCNALUnitArray));
    size_t nal_unit_size = 1024;
    for (size_t i = 0; i < num_arrays; i++) {
        arrays[i].array_completeness = 1;
        arrays[i].NAL_unit_type = (i == num_arrays - 1) ? target_type : (uint8_t)(i % 64);
        arrays[i].numNalus = 1;
        arrays[i].nalUnitLength = create_uint16_array(arrays[i].numNalus);
        arrays[i].nalUnit = create_uint8_matrix(arrays[i].numNalus, nal_unit_size);
    }
    return arrays;
}

void init_vars() {
    nal_type = 32;
    hvcc = malloc(sizeof(HEVCDecoderConfigurationRecord));
    hvcc->numOfArrays = 50000;
    hvcc->array = create_hvcc_array(hvcc->numOfArrays, nal_type);
}

void loop(); 

void __attribute__((constructor)) init() {
    init_vars();
    loop();
}