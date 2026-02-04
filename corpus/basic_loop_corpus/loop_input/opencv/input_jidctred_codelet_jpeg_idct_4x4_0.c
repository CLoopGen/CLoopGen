#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

JLONG tmp0;
JLONG tmp2;
JLONG tmp10;
JLONG tmp12;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;

JCOEF inbuf[64];
ISLOW_MULT_TYPE quantbuf[64];
int wsbuf[64];

JCOEFPTR inptr = inbuf;
ISLOW_MULT_TYPE *quantptr = quantbuf;
int *wsptr = wsbuf;
int ctr;

void init_vars() {
    for (int i = 0; i < 64; i++) {
        inbuf[i] = (JCOEF)(i % 17 - 8);
        quantbuf[i] = (ISLOW_MULT_TYPE)(i % 13 + 1);
        wsbuf[i] = 0;
    }
    tmp0 = 0;
    tmp2 = 0;
    tmp10 = 0;
    tmp12 = 0;
    z1 = 0;
    z2 = 0;
    z3 = 0;
    z4 = 0;
    ctr = 8;
    inptr = inbuf;
    quantptr = quantbuf;
    wsptr = wsbuf;
}