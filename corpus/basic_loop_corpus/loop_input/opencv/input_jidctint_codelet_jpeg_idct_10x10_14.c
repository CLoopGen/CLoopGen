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
INT32 tmp20;
INT32 tmp21;
INT32 tmp22;
INT32 tmp23;
INT32 tmp24;
INT32 z1;
INT32 z2;
INT32 z3;
INT32 z4;
INT32 z5;

short inbuf[64 * 32768]; // 32768 blocks of 8x8 coefficients
int quantbuf[64 * 32768]; // matching quantization tables
int wsbuf[64 * 32768]; // workspace storage

JCOEFPTR inptr = inbuf;
ISLOW_MULT_TYPE *quantptr = quantbuf;
int *wsptr = wsbuf;
int ctr;

void init_vars() {
    for (int i = 0; i < 64 * 32768; i++) {
        inbuf[i] = (short)((i * 73) % 128 - 64);
        quantbuf[i] = (i * 101) % 100 + 1;
        wsbuf[i] = 0;
    }
}