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
INT32 z1;
INT32 z2;
INT32 z3;

short inbuf[64 * 32768];           // 64 * 32768 = 2MB of input data
ISLOW_MULT_TYPE quantbuf[64 * 32768]; // Matched size
int wsbuf[64 * 32768];              // Workspace buffer

JCOEFPTR inptr = inbuf;
ISLOW_MULT_TYPE *quantptr = quantbuf;
int *wsptr = wsbuf;
int ctr;

void init_vars() {
    for (int i = 0; i < 64 * 32768; i++) {
        inbuf[i] = (short)((i * 17) & 511); // Non-zero pattern
        quantbuf[i] = (ISLOW_MULT_TYPE)((i * 97) & 255);
        wsbuf[i] = 0;
    }
}