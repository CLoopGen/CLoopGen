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
    float local_v = params->v;
    float prev_dst = 0.0f;
    for (int i = 0; i < dims_count; ++i) {
        float current_src = src[i];
        float computed_val = (local_v > current_src) ? current_src : local_v;
        dst[i] = computed_val + prev_dst;
        prev_dst = computed_val;
    }
}
