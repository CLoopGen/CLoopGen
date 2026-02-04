#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef float FLOAT_MULT_TYPE;

float tmp0;
float tmp1;
float tmp2;
float tmp3;
float tmp4;
float tmp5;
float tmp6;
float tmp7;
float tmp10;
float tmp11;
float tmp12;
float tmp13;
float z5;
float z10;
float z11;
float z12;
float z13;

JCOEF *inptr;
FLOAT_MULT_TYPE *quantptr;
float *wsptr;
int ctr;

#define DATA_SIZE (1 << 20)

static JCOEF in_data[8 * DATA_SIZE] __attribute__((aligned(32)));
static FLOAT_MULT_TYPE quant_data[8 * DATA_SIZE] __attribute__((aligned(32)));
static float ws_data[8 * DATA_SIZE] __attribute__((aligned(32)));

void init_vars() {
    for (int i = 0; i < 8 * DATA_SIZE; i++) {
        in_data[i] = (JCOEF)(i % 251);
        quant_data[i] = (FLOAT_MULT_TYPE)(1.0 + (i % 50) * 0.01);
        ws_data[i] = 0.0f;
    }
    inptr = in_data;
    quantptr = quant_data;
    wsptr = ws_data;
    ctr = 8;
}