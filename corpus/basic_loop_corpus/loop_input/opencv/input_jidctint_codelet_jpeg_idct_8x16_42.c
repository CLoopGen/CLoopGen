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
INT32 tmp20;
INT32 tmp21;
INT32 tmp22;
INT32 tmp23;
INT32 tmp24;
INT32 tmp25;
INT32 tmp26;
INT32 tmp27;
INT32 z1;
INT32 z2;
INT32 z3;
INT32 z4;

JCOEF *inptr;
ISLOW_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024)
#define BLOCKS ((DATA_SIZE + 7) / 8)

static JCOEF in_data[8][BLOCKS];
static ISLOW_MULT_TYPE quant_data[8][BLOCKS];
static int ws_data[16][BLOCKS];

void init_vars() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < BLOCKS; j++) {
            in_data[i][j] = (JCOEF)(i * 13 + j * 7);
            quant_data[i][j] = (ISLOW_MULT_TYPE)(i * 17 + j * 11);
            ws_data[i][j] = 0;
        }
    }

    inptr = &in_data[0][0];
    quantptr = &quant_data[0][0];
    wsptr = &ws_data[0][0];
    ctr = 0;
}