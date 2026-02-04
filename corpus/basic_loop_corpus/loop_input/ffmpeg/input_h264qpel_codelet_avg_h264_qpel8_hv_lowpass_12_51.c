#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(uint16_t))

int32_t *tmp;
uint16_t *src;
int tmpStride;
int srcStride;
int h;
int pad;
int i;

void init_vars() {
    const int width = 11; 
    const int output_width = 8;
    const int total_tmp_elements = (TOTAL_ELEMENTS / width) * output_width;

    uint16_t *src_base = (uint16_t*)calloc(TOTAL_ELEMENTS, sizeof(uint16_t));
    int32_t *tmp_base = (int32_t*)calloc(total_tmp_elements, sizeof(int32_t));

    if (!src_base || !tmp_base) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < TOTAL_ELEMENTS; ++idx) {
        src_base[idx] = (uint16_t)(idx % 1024);
    }

    tmp = tmp_base;
    src = src_base + 2; 

    tmpStride = output_width;
    srcStride = width;
    h = (int)(TOTAL_ELEMENTS / width) - 5; 
    pad = 10;
    i = 0;
}