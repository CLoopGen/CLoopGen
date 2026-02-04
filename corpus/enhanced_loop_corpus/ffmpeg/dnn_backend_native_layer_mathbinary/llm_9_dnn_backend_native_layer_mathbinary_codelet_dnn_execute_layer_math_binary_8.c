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
    int step = 2;
    int limit = (dims_count % 2 == 0) ? dims_count : dims_count - 1;
    for (int i = 0; i < limit; i += step) {
        dst[i]     = params->v / src[i];
        dst[i + 1] = params->v / src[i + 1];
    }
    // Handle odd leftover element
    if (dims_count % 2 != 0) {
        dst[dims_count - 1] = params->v / src[dims_count - 1];
    }
}
