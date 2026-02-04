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
JLONG tmp27;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;

static JCOEF inbuf[64 * 32768];         // 64 * 32768 = 2MB of input data
static ISLOW_MULT_TYPE quantbuf[64 * 32768];  // Matching quantptr size
static int wsbuf[64 * 32768];           // Workspace buffer

JCOEFPTR inptr = inbuf;
ISLOW_MULT_TYPE *quantptr = quantbuf;
int *wsptr = wsbuf;
int ctr;

void init_vars() {
    const int size = 64 * 32768;
    for (int i = 0; i < size; i++) {
        inbuf[i] = (JCOEF)(i % 256 - 128);
        quantbuf[i] = (ISLOW_MULT_TYPE)(i % 100 + 1);
        wsbuf[i] = 0;
    }
}