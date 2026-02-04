#include <stdio.h>
#include <inttypes.h>

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

#define DATA_SIZE 65536

static JCOEF in_data[DATA_SIZE * 8];
static FLOAT_MULT_TYPE quant_data[DATA_SIZE * 8];
static float wsptr_data[DATA_SIZE * 8];

JCOEFPTR inptr = in_data;
FLOAT_MULT_TYPE *quantptr = quant_data;
float *wsptr = wsptr_data;
int ctr;

void init_vars() {
    for (int i = 0; i < DATA_SIZE * 8; i++) {
        in_data[i] = (short)(i % 257 - 128);
        quant_data[i] = (float)(1.0 + (i % 64) * 0.1);
        wsptr_data[i] = 0.0f;
    }
}