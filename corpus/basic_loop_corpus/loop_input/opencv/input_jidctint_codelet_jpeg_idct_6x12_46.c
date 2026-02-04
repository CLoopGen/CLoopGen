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

short inbuf_data[64 * 4096];
ISLOW_MULT_TYPE quantbuf_data[64 * 4096];
int wsptr_data[12 * 4096];

JCOEFPTR inptr = inbuf_data;
ISLOW_MULT_TYPE *quantptr = quantbuf_data;
int *wsptr = wsptr_data;
int ctr;

void init_vars() {
    for (int i = 0; i < 64 * 4096; i++) {
        inbuf_data[i] = (short)(i % 32767);
        quantbuf_data[i] = (ISLOW_MULT_TYPE)(i % 1000 + 1);
    }
    for (int i = 0; i < 12 * 4096; i++) {
        wsptr_data[i] = 0;
    }
}