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
INT32 tmp20;
INT32 tmp21;
INT32 tmp22;
INT32 tmp23;
INT32 tmp24;
INT32 tmp25;
INT32 z1;
INT32 z2;
INT32 z3;
INT32 z4;

short inbuf[64 * 32768]; // 128KB of input data (8*8 blocks)
ISLOW_MULT_TYPE quantbuf[64 * 32768]; // matching quantization table
int wsbuf[64 * 32768]; // workspace buffer

JCOEFPTR inptr = inbuf;
ISLOW_MULT_TYPE *quantptr = quantbuf;
int *wsptr = wsbuf;
int ctr;

void init_vars() {
    const int num_blocks = 32768;
    for (int i = 0; i < 64 * num_blocks; i++) {
        inbuf[i] = (short)((i * 7) % 128 - 64);
        quantbuf[i] = (ISLOW_MULT_TYPE)((i * 11) % 256 + 1);
        wsbuf[i] = 0;
    }
}