#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef long JLONG;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

JLONG tmp0;
JLONG tmp2;
JLONG tmp10;
JLONG tmp12;
JCOEFPTR inptr;
ISLOW_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024 / sizeof(JCOEF))

static JCOEF in_buffer[TOTAL_ELEMENTS];
static ISLOW_MULT_TYPE quant_buffer[TOTAL_ELEMENTS];
static int ws_buffer[TOTAL_ELEMENTS];

void init_vars() {
    const double factor1 = 0.70710678100000002;
    const double factor2 = 1.224744871;
    const JLONG shift_val = ((JLONG)1) << 13;

    for (int i = 0; i < TOTAL_ELEMENTS; i++) {
        in_buffer[i] = (JCOEF)(i % 256 - 128);
        quant_buffer[i] = (ISLOW_MULT_TYPE)(i % 100 + 1);
        ws_buffer[i] = 0;
    }

    tmp0 = 0;
    tmp2 = 0;
    tmp10 = 0;
    tmp12 = 0;
    ctr = 0;

    inptr = in_buffer;
    quantptr = quant_buffer;
    wsptr = ws_buffer;
}