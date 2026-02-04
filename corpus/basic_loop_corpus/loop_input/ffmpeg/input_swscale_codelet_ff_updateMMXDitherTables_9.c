#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int hasAlpha = 1;
int vLumFilterSize = 64;
int dstY = 0;
int i = 0;
int s = 2;

int16_t *vLumFilter;
int32_t *lumMmxFilter;
int32_t *alpMmxFilter;
int16_t **lumSrcPtr;
int16_t **alpSrcPtr;

void init_vars() {
    const size_t total_data_size = 128 * 1024 * 1024; // Aim for ~128MB
    size_t lum_filter_bytes = vLumFilterSize * sizeof(int16_t);
    size_t mmx_filter_elements = (total_data_size / (s * 2 * sizeof(int32_t))) + 1;
    size_t ptr_array_elements = (mmx_filter_elements + 1) / s;

    vLumFilter = (int16_t *)calloc(vLumFilterSize, sizeof(int16_t));
    lumMmxFilter = (int32_t *)calloc(mmx_filter_elements * s, sizeof(int32_t));
    alpMmxFilter = (int32_t *)calloc(mmx_filter_elements * s, sizeof(int32_t));
    lumSrcPtr = (int16_t **)calloc(ptr_array_elements, sizeof(int16_t *));
    alpSrcPtr = (int16_t **)calloc(ptr_array_elements, sizeof(int16_t *));

    for (int idx = 0; idx < ptr_array_elements; idx++) {
        lumSrcPtr[idx] = (int16_t *)calloc(16, sizeof(int16_t));
        alpSrcPtr[idx] = (int16_t *)calloc(16, sizeof(int16_t));
    }

    for (int idx = 0; idx < vLumFilterSize; idx++) {
        vLumFilter[idx] = (int16_t)(idx * 7);
    }

    dstY = 0;
    s = 2;
    hasAlpha = 1;
}