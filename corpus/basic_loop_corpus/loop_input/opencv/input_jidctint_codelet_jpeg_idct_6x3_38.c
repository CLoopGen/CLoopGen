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
JCOEFPTR inptr;
ISLOW_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024)  // ~64MB to target 0.01s runtime

static JCOEF in_data[DATA_SIZE];
static ISLOW_MULT_TYPE quant_data[DATA_SIZE];
static int ws_data[DATA_SIZE];

void init_vars() {
    for (int i = 0; i < DATA_SIZE; i++) {
        in_data[i] = (JCOEF)(i % 32768);
        quant_data[i] = (ISLOW_MULT_TYPE)(i % 16384);
        ws_data[i] = 0;
    }

    inptr = in_data;
    quantptr = quant_data;
    wsptr = ws_data;
    ctr = 0;
}