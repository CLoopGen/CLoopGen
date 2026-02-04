#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

union {
    uint32_t u32;
    float y;
};

typedef struct DnnLayerMaximumParams {
    union {
        uint32_t u32;
        float y;
    } val;
} DnnLayerMaximumParams;

DnnLayerMaximumParams *params;
int dims_count;
float *src;
float *dst;

void init_vars() {
    dims_count = 65536 * 4;  // ~1MB for two float arrays (src and dst): 65536*4*2*4 = 2MB

    params = (DnnLayerMaximumParams*)malloc(sizeof(DnnLayerMaximumParams));
    if (!params) exit(1);
    params->val.y = 0.5f;

    src = (float*)malloc(dims_count * sizeof(float));
    dst = (float*)malloc(dims_count * sizeof(float));
    if (!src || !dst) exit(1);

    for (int i = 0; i < dims_count; ++i) {
        src[i] = (float)(rand() % 1000) / 100.0f;
    }
}