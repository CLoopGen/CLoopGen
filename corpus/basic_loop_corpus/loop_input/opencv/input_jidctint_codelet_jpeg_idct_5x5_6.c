#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

JLONG tmp0;
JLONG tmp1;
JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG z1;
JLONG z2;
JLONG z3;

short inbuf_data[64 * 5];  // Simulate input coefficients: 8*8 blocks, 5 instances
int quant_data[64 * 5];    // Quantization table scaled values
int ws_data[25 * 5];       // Workspace storage: 5x5 per block, 5 instances

JCOEFPTR inptr = inbuf_data;
ISLOW_MULT_TYPE *quantptr = quant_data;
int *wsptr = ws_data;
int ctr;

void init_vars() {
    for (int i = 0; i < 64 * 5; i++) {
        inbuf_data[i] = (short)(i % 257 - 128);  // Populate with sample data in valid range
        quant_data[i] = (i % 251) + 1;           // Avoid zero to prevent division-like issues
    }
    for (int i = 0; i < 25 * 5; i++) {
        ws_data[i] = 0;
    }
    ctr = 0;
}