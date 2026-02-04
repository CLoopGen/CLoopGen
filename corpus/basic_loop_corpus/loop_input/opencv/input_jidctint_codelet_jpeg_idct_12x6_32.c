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
INT32 z1;
INT32 z2;
INT32 z3;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01 sec runtime

static JCOEF in_data[DATA_SIZE];
static ISLOW_MULT_TYPE quant_data[DATA_SIZE];
static int ws_data[DATA_SIZE];

JCOEFPTR inptr = in_data;
ISLOW_MULT_TYPE *quantptr = quant_data;
int *wsptr = ws_data;
int ctr;

void init_vars() {
    for (int i = 0; i < DATA_SIZE; i++) {
        in_data[i] = (JCOEF)(i % 32768);
        quant_data[i] = (ISLOW_MULT_TYPE)(i % 1000 + 1);
        ws_data[i] = 0;
    }
}