#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
INT32 z4;
INT32 z5;
JCOEFPTR inptr;
ISLOW_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

#define DATA_SIZE (65536)

static JCOEF in_data[8 * DATA_SIZE] __attribute__((aligned(32)));
static ISLOW_MULT_TYPE quant_data[8 * DATA_SIZE] __attribute__((aligned(32)));
static int ws_data[8 * DATA_SIZE] __attribute__((aligned(32)));

void init_vars() {
    for (int i = 0; i < 8 * DATA_SIZE; i++) {
        in_data[i] = (JCOEF)((i % 7) ? ((i * 17) & 0x7F) - 64 : ((i * 91) & 0xFF) - 128);
        quant_data[i] = (ISLOW_MULT_TYPE)(1 + ((i * 13) & 0x3F));
        ws_data[i] = 0;
    }

    inptr = in_data;
    quantptr = quant_data;
    wsptr = ws_data;
    ctr = 0;
}