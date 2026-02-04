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
INT32 tmp3;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 z1;
INT32 z2;
INT32 z3;

#define DATA_SIZE (16 * 1024 * 1024)
#define BLOCKS (DATA_SIZE / 8)

static JCOEF in_data[DATA_SIZE];
static ISLOW_MULT_TYPE quant_data[DATA_SIZE];
static int ws_data[DATA_SIZE];

JCOEFPTR inptr;
ISLOW_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

void init_vars() {
    for (int i = 0; i < DATA_SIZE; i++) {
        in_data[i] = (JCOEF)(i % 251);
        quant_data[i] = (ISLOW_MULT_TYPE)(i % 199 + 1);
        ws_data[i] = 0;
    }

    inptr = in_data;
    quantptr = quant_data;
    wsptr = ws_data;
    ctr = 8;
}