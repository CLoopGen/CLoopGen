#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG tmp13;
JLONG tmp14;
JLONG tmp15;
JLONG tmp16;
JLONG tmp20;
JLONG tmp21;
JLONG tmp22;
JLONG tmp23;
JLONG tmp24;
JLONG tmp25;
JLONG tmp26;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;

JCOEF *inptr;
ISLOW_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

static JCOEF in_data[64 * 32768];           // 64 * 32768 * sizeof(short) = 4MB
static ISLOW_MULT_TYPE quant_data[64 * 32768]; // Same size for quantptr
static int ws_data[64 * 32768];             // Same size for wsptr

void init_vars() {
    for (int i = 0; i < 64 * 32768; i++) {
        in_data[i] = (JCOEF)(i % 256 - 128);
        quant_data[i] = (ISLOW_MULT_TYPE)(i % 100 + 1);
        ws_data[i] = 0;
    }

    inptr = in_data;
    quantptr = quant_data;
    wsptr = ws_data;
    ctr = 0;
}