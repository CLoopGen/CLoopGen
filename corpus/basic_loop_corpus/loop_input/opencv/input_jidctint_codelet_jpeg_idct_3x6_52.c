#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 z1;
INT32 z2;
INT32 z3;

short inbuf[64 * 8];
ISLOW_MULT_TYPE quantbuf[64 * 8];
int wsbuf[64 * 8];

JCOEFPTR inptr = inbuf;
ISLOW_MULT_TYPE *quantptr = quantbuf;
int *wsptr = wsbuf;
int ctr;

void init_vars() {
    for (int i = 0; i < 64 * 8; i++) {
        inbuf[i] = (short)((i * 73) % 100 - 50);
        quantbuf[i] = (ISLOW_MULT_TYPE)((i * 97) % 100 + 1);
        wsbuf[i] = 0;
    }
}