#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

#define DATA_SIZE (1 << 20)  // ~1MB of input data

JLONG tmp0;
JLONG tmp10;
JLONG z1;

JCOEF *inptr;
ISLOW_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

static JCOEF in_data[8 * 8];
static ISLOW_MULT_TYPE quant_data[8 * 8];
static int ws_data[8 * 8];

void init_vars() {
    inptr = in_data;
    quantptr = quant_data;
    wsptr = ws_data;
    ctr = 8;

    for (int i = 0; i < 8 * 8; i++) {
        in_data[i] = (JCOEF)(i % 257 - 128);
        quant_data[i] = (ISLOW_MULT_TYPE)(i % 100 + 1);
        ws_data[i] = 0;
    }
}