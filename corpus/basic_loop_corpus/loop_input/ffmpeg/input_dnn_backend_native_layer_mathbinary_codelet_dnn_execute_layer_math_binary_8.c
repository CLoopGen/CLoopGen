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
    dims_count = 67108864; // ~256MB: 67M elements * 4 bytes per float * 2 arrays ≈ 256MB

    params = (DnnLayerMathBinaryParams*)malloc(sizeof(DnnLayerMathBinaryParams));
    if (!params) exit(1);
    params->bin_op = DMBO_REALDIV;
    params->input0_broadcast = 0;
    params->input1_broadcast = 0;
    params->v = 1.0f;

    src = (float*)malloc(dims_count * sizeof(float));
    dst = (float*)malloc(dims_count * sizeof(float));
    if (!src || !dst) exit(1);

    for (int i = 0; i < dims_count; ++i) {
        src[i] = 1.0f + (i & 1 ? 0.1f : -0.1f); // Avoid division by zero
    }
}