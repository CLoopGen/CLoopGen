#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;
typedef JLONG DCTELEM;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef JLONG IFAST_MULT_TYPE;

DCTELEM tmp0;
DCTELEM tmp1;
DCTELEM tmp2;
DCTELEM tmp3;
DCTELEM tmp4;
DCTELEM tmp5;
DCTELEM tmp6;
DCTELEM tmp7;
DCTELEM tmp10;
DCTELEM tmp11;
DCTELEM tmp12;
DCTELEM tmp13;
DCTELEM z5;
DCTELEM z10;
DCTELEM z11;
DCTELEM z12;
DCTELEM z13;

JCOEFPTR inptr;
IFAST_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

#define DATA_SIZE (65536)

static JCOEF in_data[8 * DATA_SIZE];
static IFAST_MULT_TYPE quant_data[8 * DATA_SIZE];
static int ws_data[8 * DATA_SIZE];

void init_vars() {
    for (int i = 0; i < 8 * DATA_SIZE; i++) {
        in_data[i] = (JCOEF)(i % 256 - 128);
        quant_data[i] = (IFAST_MULT_TYPE)(i % 50 + 1);
        ws_data[i] = 0;
    }

    inptr = in_data;
    quantptr = quant_data;
    wsptr = ws_data;
    ctr = 8;
}