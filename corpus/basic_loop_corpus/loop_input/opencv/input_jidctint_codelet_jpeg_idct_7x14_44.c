#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 tmp14;
INT32 tmp15;
INT32 tmp16;
INT32 tmp20;
INT32 tmp21;
INT32 tmp22;
INT32 tmp23;
INT32 tmp24;
INT32 tmp25;
INT32 tmp26;
INT32 z1;
INT32 z2;
INT32 z3;
INT32 z4;

static JCOEF inbuf[64 * 16384];         // 64 * 16384 = 1MB of input data
static ISLOW_MULT_TYPE quantbuf[64 * 16384]; // Matched size
static int wsbuf[14 * 16384];          // wsptr accesses up to index 13, so we need at least 14 per block

JCOEFPTR inptr = inbuf;
ISLOW_MULT_TYPE *quantptr = quantbuf;
int *wsptr = wsbuf;
int ctr = 0;

void init_vars() {
    for (int i = 0; i < 64 * 16384; i++) {
        inbuf[i] = (JCOEF)((i * 73) % 8192 - 4096); // Spread over typical coefficient range
        quantbuf[i] = (ISLOW_MULT_TYPE)((i * 101) % 4096 + 1); // Avoid zero
    }
    for (int i = 0; i < 14 * 16384; i++) {
        wsbuf[i] = 0; // Clear output workspace
    }

    tmp10 = 0;
    tmp11 = 0;
    tmp12 = 0;
    tmp13 = 0;
    tmp14 = 0;
    tmp15 = 0;
    tmp16 = 0;
    tmp20 = 0;
    tmp21 = 0;
    tmp22 = 0;
    tmp23 = 0;
    tmp24 = 0;
    tmp25 = 0;
    tmp26 = 0;
    z1 = 0;
    z2 = 0;
    z3 = 0;
    z4 = 0;
    ctr = 0;
    inptr = inbuf;
    quantptr = quantbuf;
    wsptr = wsbuf;
}