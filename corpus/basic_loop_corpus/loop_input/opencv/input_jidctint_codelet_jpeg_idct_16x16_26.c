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

static JCOEF inbuf[64 * 32768];        // 32768 blocks of 8x8 input
static ISLOW_MULT_TYPE quantbuf[64 * 32768];  // Quantization tables
static int wsbuf[16 * 32768];          // Workspace: 16 per block

JCOEFPTR inptr;
ISLOW_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

void init_vars() {
    const int num_blocks = 32768;  // Adjust to tune runtime (~0.01 sec on modern CPU)
    
    // Initialize input and quantization data
    for (int i = 0; i < 64 * num_blocks; i++) {
        inbuf[i] = (JCOEF)((i * 17 + 97) % 255 - 128);  // Random-like small values
        quantbuf[i] = (ISLOW_MULT_TYPE)((i * 31 + 73) % 255 + 1);  // Avoid zero
    }
    
    // Initialize workspace to zero
    for (int i = 0; i < 16 * num_blocks; i++) {
        wsbuf[i] = 0;
    }

    // Set pointers to first block
    inptr = inbuf;
    quantptr = quantbuf;
    wsptr = wsbuf;

    // Initialize scalar temporaries to zero
    tmp0 = 0;
    tmp1 = 0;
    tmp2 = 0;
    tmp3 = 0;
    tmp10 = 0;
    tmp11 = 0;
    tmp12 = 0;
    tmp13 = 0;
    tmp20 = 0;
    tmp21 = 0;
    tmp22 = 0;
    tmp23 = 0;
    tmp24 = 0;
    tmp25 = 0;
    tmp26 = 0;
    tmp27 = 0;
    z1 = 0;
    z2 = 0;
    z3 = 0;
    z4 = 0;

    ctr = 0;
}