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
JLONG tmp20;
JLONG tmp21;
JLONG tmp22;
JLONG tmp23;
JLONG tmp24;
JLONG tmp25;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(JCOEF))  // ~128MB of data

static JCOEF inbuf[DATA_SIZE];
static ISLOW_MULT_TYPE quantbuf[DATA_SIZE];
static int wsbuf[DATA_SIZE * 11];  // enough for wsptr[8*10] indexing with margin

JCOEFPTR inptr = inbuf;
ISLOW_MULT_TYPE *quantptr = quantbuf;
int *wsptr = wsbuf;
int ctr;

void init_vars() {
    for (int i = 0; i < DATA_SIZE; i++) {
        inbuf[i] = (JCOEF)(i % 256 - 128);
        quantbuf[i] = (ISLOW_MULT_TYPE)(i % 100 + 1);
    }
    for (int i = 0; i < DATA_SIZE * 11; i++) {
        wsbuf[i] = 0;
    }
    tmp10 = 0; tmp11 = 0; tmp12 = 0; tmp13 = 0; tmp14 = 0;
    tmp20 = 0; tmp21 = 0; tmp22 = 0; tmp23 = 0; tmp24 = 0; tmp25 = 0;
    z1 = 0; z2 = 0; z3 = 0; z4 = 0;
    ctr = 0;
    inptr = inbuf;
    quantptr = quantbuf;
    wsptr = wsbuf;
}