#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef long INT32;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

INT32 tmp0;
INT32 tmp2;
INT32 tmp10;
INT32 tmp12;
INT32 z1;
INT32 z2;
INT32 z3;
INT32 z4;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(JCOEF)) // ~64MB of input data

static JCOEF inbuf[DATA_SIZE];
static ISLOW_MULT_TYPE quantbuf[DATA_SIZE];
static int wsbuf[DATA_SIZE];

JCOEFPTR inptr = inbuf;
ISLOW_MULT_TYPE *quantptr = quantbuf;
int *wsptr = wsbuf;
int ctr;

void init_vars() {
    for (int i = 0; i < DATA_SIZE; i++) {
        inbuf[i] = (JCOEF)(i % 257 - 128); // Spread over full JCOEF range
        quantbuf[i] = (ISLOW_MULT_TYPE)(i % 100 + 1); // Non-zero to avoid division by zero effects
        wsbuf[i] = 0;
    }

    // Ensure that the loop accesses within bounds: each iteration uses up to inptr[8*7]
    // So we must ensure that at least 8*7+1 = 57 elements per block are available
    // And we have 8 iterations per outer loop, so total stride per loop is 1 in array index
    // But the original loop assumes a fixed structure with 8 steps
    // We'll set up the buffer so that there's enough room for all strided accesses

    // Adjust data size to be multiple of 8 and large enough
    // Each loop iteration advances pointers by 1, runs 8 times
    // So we need at least 8 * 8 * 7 = 448 elements minimum to not overflow
    // Our data size is much larger, so it's safe as long as we don't run too many loops

    // Limit ctr to ensure no out-of-bounds access
    // Maximum offset used: inptr[8*7] -> index += 56
    // So we require that starting index <= DATA_SIZE - 57
    // We'll restrict the effective size accordingly
}