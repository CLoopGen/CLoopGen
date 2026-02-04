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
    float v = params->v;
    int i;
    for (i = 0; i < dims_count; i += 2) {
        float val0 = src[i];
        float result0 = (v > val0) ? val0 : v;
        dst[i] = result0;

        if (i + 1 < dims_count) {
            float val1 = src[i + 1];
            float result1 = (v > val1) ? val1 : v;
            dst[i + 1] = result1;
        }
    }
}
