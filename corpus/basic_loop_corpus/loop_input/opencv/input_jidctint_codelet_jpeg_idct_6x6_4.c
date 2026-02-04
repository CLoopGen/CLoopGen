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
JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG z1;
JLONG z2;
JLONG z3;

short inbuf[64 * 100000]; // ~12.8MB of input data
ISLOW_MULT_TYPE quantbuf[64 * 100000]; // ~1.6MB
int wsbuf[6 * 100000]; // ~2.4MB

JCOEFPTR inptr = inbuf;
ISLOW_MULT_TYPE *quantptr = quantbuf;
int *wsptr = wsbuf;
int ctr;

void init_vars() {
    for (int i = 0; i < 64 * 100000; i++) {
        inbuf[i] = (short)((i * 17) % 128);
        quantbuf[i] = (ISLOW_MULT_TYPE)((i * 31) % 256);
    }
    for (int i = 0; i < 6 * 100000; i++) {
        wsbuf[i] = 0;
    }
}