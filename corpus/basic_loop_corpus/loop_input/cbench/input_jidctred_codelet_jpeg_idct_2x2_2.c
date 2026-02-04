#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef long INT32;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

INT32 tmp0;
INT32 tmp10;
INT32 z1;
JCOEF *inptr;
ISLOW_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01s runtime

static JCOEF in_data[8 * 8];
static ISLOW_MULT_TYPE quant_data[8 * 8];
static int ws_data[8 * 8];

void init_vars() {
    // Initialize arrays with valid data
    for (int i = 0; i < 8 * 8; i++) {
        in_data[i] = (JCOEF)(i % 257 - 128); // Spread across range
        quant_data[i] = (ISLOW_MULT_TYPE)(i % 100 + 1);
        ws_data[i] = 0;
    }

    // Set pointer bases
    inptr = in_data;
    quantptr = quant_data;
    wsptr = ws_data;

    // Initialize loop counter
    ctr = 8;
}