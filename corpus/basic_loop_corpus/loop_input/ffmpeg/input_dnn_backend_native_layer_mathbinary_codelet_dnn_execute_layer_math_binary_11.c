#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    DMBO_SUB = 0,
    DMBO_ADD = 1,
    DMBO_MUL = 2,
    DMBO_REALDIV = 3,
    DMBO_MINIMUM = 4,
    DMBO_COUNT
} DNNMathBinaryOperation;

typedef struct DnnLayerMathBinaryParams {
    DNNMathBinaryOperation bin_op;
    int input0_broadcast;
    int input1_broadcast;
    float v;
} DnnLayerMathBinaryParams;

DnnLayerMathBinaryParams *params;
int dims_count;
float *src;
float *dst;

void init_vars() {
    dims_count = 67108864;  // ~256 MB: 67M elements * 4 bytes per float * 2 arrays ≈ 256 MB

    params = (DnnLayerMathBinaryParams*)malloc(sizeof(DnnLayerMathBinaryParams));
    params->bin_op = DMBO_MINIMUM;
    params->input0_broadcast = 0;
    params->input1_broadcast = 0;
    params->v = 0.5f;

    src = (float*)malloc(dims_count * sizeof(float));
    dst = (float*)malloc(dims_count * sizeof(float));

    for (int i = 0; i < dims_count; ++i) {
        src[i] = (float)(i % 1000) / 100.0f;
        dst[i] = 0.0f;
    }
}