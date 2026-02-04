#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

INT32 tmp0;
INT32 tmp2;
INT32 tmp10;
INT32 tmp12;

JCOEF inbuf[24];
ISLOW_MULT_TYPE quantbuf[24];
int wsbuf[9];

JCOEFPTR inptr = inbuf;
ISLOW_MULT_TYPE *quantptr = quantbuf;
int *wsptr = wsbuf;
int ctr;

void init_vars() {
    for (int i = 0; i < 24; i++) {
        inbuf[i] = (JCOEF)(i * 7 % 128);
        quantbuf[i] = (ISLOW_MULT_TYPE)(i * 13 + 1);
    }
    for (int i = 0; i < 9; i++) {
        wsbuf[i] = 0;
    }
    tmp0 = 0;
    tmp2 = 0;
    tmp10 = 0;
    tmp12 = 0;
    ctr = 0;
}