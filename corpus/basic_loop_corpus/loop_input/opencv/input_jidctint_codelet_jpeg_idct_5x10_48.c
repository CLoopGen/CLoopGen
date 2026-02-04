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

JCOEF inbuf[64 * 50000];
ISLOW_MULT_TYPE quantbuf[64 * 50000];
int wsbuf[10 * 50000];

JCOEFPTR inptr;
ISLOW_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

void init_vars() {
    const int num_iterations = 50000;
    
    inptr = inbuf;
    quantptr = quantbuf;
    wsptr = wsbuf;
    ctr = 0;

    for (int i = 0; i < 64 * num_iterations; i++) {
        inbuf[i] = (JCOEF)(i % 257 - 128);
        quantbuf[i] = (ISLOW_MULT_TYPE)(i % 101 + 1);
    }

    for (int i = 0; i < 10 * num_iterations; i++) {
        wsbuf[i] = 0;
    }
}