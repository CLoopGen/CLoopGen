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
INT32 tmp20;
INT32 tmp21;
INT32 tmp22;
INT32 tmp23;
INT32 z1;
INT32 z2;
INT32 z3;

JCOEF inbuf[64 * 32768]; // 64 * 32768 = 2MB of JCOEF (short), ~1MB data
ISLOW_MULT_TYPE quantbuf[64 * 32768];
int wsbuf[64 * 32768];

JCOEFPTR inptr;
ISLOW_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

void init_vars() {
    inptr = inbuf + 8;
    quantptr = quantbuf + 8;
    wsptr = wsbuf + 8;

    for (int i = 0; i < 64 * 32768; i++) {
        inbuf[i] = (JCOEF)(i % 251);
        quantbuf[i] = (ISLOW_MULT_TYPE)(i % 199);
        wsbuf[i] = 0;
    }
}