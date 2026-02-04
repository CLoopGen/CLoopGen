#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

JLONG tmp0;
JLONG tmp1;
JLONG tmp2;
JLONG tmp3;
JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG tmp13;
JLONG tmp14;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;

JCOEF inbuf[64 * 32768]; // 64 * 32768 = 2MB of input data (8x8 blocks, 32768 blocks)
ISLOW_MULT_TYPE quantbuf[64 * 32768];
int wsbuf[64 * 32768];

JCOEFPTR inptr;
ISLOW_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

void init_vars() {
    for (int i = 0; i < 64 * 32768; i++) {
        inbuf[i] = (JCOEF)(i % 257 - 128);
        quantbuf[i] = (ISLOW_MULT_TYPE)(i % 129 + 1);
        wsbuf[i] = 0;
    }

    inptr = inbuf;
    quantptr = quantbuf;
    wsptr = wsbuf;
    ctr = 0;
}