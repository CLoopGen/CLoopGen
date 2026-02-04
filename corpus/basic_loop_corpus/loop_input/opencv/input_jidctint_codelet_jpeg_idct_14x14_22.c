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

#define DATA_SIZE 65536

static JCOEF inbuf[DATA_SIZE];
static ISLOW_MULT_TYPE quantbuf[DATA_SIZE];
static int wsbuf[DATA_SIZE];

JCOEFPTR inptr = inbuf;
ISLOW_MULT_TYPE *quantptr = quantbuf;
int *wsptr = wsbuf;
int ctr;

void init_vars() {
    for (int i = 0; i < DATA_SIZE; i++) {
        inbuf[i] = (JCOEF)(i % 32768);
        quantbuf[i] = (ISLOW_MULT_TYPE)(i % 1000 + 1);
        wsbuf[i] = 0;
    }
}