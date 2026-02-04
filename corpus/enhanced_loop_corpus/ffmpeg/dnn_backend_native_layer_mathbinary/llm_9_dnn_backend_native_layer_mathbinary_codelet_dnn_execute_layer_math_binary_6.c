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

extern  DnnLayerMathBinaryParams *params;
extern int dims_count;
extern  float *src;
extern float *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int unroll_factor = 4;
    int limit = (dims_count / unroll_factor) * unroll_factor;
    for (int i = 0; i < limit; i += unroll_factor) {
        dst[i]     = params->v * (src[i] + 0.5f);
        dst[i + 1] = params->v * (src[i + 1] + 0.5f);
        dst[i + 2] = params->v * (src[i + 2] + 0.5f);
        dst[i + 3] = params->v * (src[i + 3] + 0.5f);
    }
    for (int i = limit; i < dims_count; ++i) {
        dst[i] = params->v * src[i];
    }
}
