#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int stride;
int ref_stride;
uint8_t *ref_ptr;
float *ptr;
float factor;
int h;
int w;
int i;
int j;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(float))

static uint8_t *ref_data;
static float *ptr_data;

void init_vars() {
    factor = 1.5f;
    h = 4096;
    w = 4096;

    ref_stride = w * sizeof(uint8_t);
    stride = w * sizeof(float);

    size_t ref_data_size = (size_t)h * w * sizeof(uint8_t);
    size_t ptr_data_size = (size_t)h * w * sizeof(float);

    ref_data = (uint8_t*)aligned_alloc(32, ref_data_size);
    ptr_data = (float*)aligned_alloc(32, ptr_data_size);

    if (!ref_data || !ptr_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < h * w; idx++) {
        ref_data[idx] = (uint8_t)(idx % 256);
        ptr_data[idx] = 0.0f;
    }

    ref_ptr = ref_data;
    ptr = ptr_data;
}