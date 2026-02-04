#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int stride;
int ref_stride;
uint16_t *ref_ptr;
float *ptr;
float factor;
int h;
int w;
int i;
int j;

static uint16_t *ref_data;
static float *ptr_data;

void init_vars() {
    h = 1024;
    w = 1024;
    factor = 1.5f;
    stride = w * sizeof(float);
    ref_stride = w * sizeof(uint16_t);

    ref_data = (uint16_t*)aligned_alloc(32, h * w * sizeof(uint16_t));
    ptr_data = (float*)aligned_alloc(32, h * w * sizeof(float));

    if (!ref_data || !ptr_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < h * w; idx++) {
        ref_data[idx] = (uint16_t)(idx % 65535);
        ptr_data[idx] = 0.0f;
    }

    ref_ptr = ref_data;
    ptr = ptr_data;
}