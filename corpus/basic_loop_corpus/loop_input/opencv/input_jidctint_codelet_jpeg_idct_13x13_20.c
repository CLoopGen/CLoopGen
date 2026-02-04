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
INT32 tmp26;
INT32 z1;
INT32 z2;
INT32 z3;
INT32 z4;

short inbuf_data[64 * 32768]; 
ISLOW_MULT_TYPE quantbuf_data[64 * 32768]; 
int wsptr_data[16 * 8 * 32768]; 

JCOEFPTR inptr = inbuf_data;
ISLOW_MULT_TYPE *quantptr = quantbuf_data;
int *wsptr = wsptr_data;
int ctr;

void init_vars() {
    const int total_iterations = 32768; 

    for (int i = 0; i < 64 * total_iterations; i++) {
        inbuf_data[i] = (short)(i % 257 - 128);
        quantbuf_data[i] = (ISLOW_MULT_TYPE)(i % 101 + 1);
    }

    for (int i = 0; i < 16 * 8 * total_iterations; i++) {
        wsptr_data[i] = 0;
    }

    ctr = 0;
}