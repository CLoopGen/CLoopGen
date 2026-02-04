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
JLONG tmp2;
JLONG tmp3;
JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG tmp13;
JLONG tmp20;
JLONG tmp21;
JLONG tmp22;
JLONG tmp23;
JLONG tmp24;
JLONG tmp25;
JLONG tmp26;
JLONG tmp27;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(JCOEF)) // ~64MB of input data

static JCOEF inbuf[DATA_SIZE];
static ISLOW_MULT_TYPE quantbuf[DATA_SIZE];
static int wsbuf[DATA_SIZE];

JCOEFPTR inptr;
ISLOW_MULT_TYPE *quantptr;
int *wsptr;
int ctr;

void init_vars() {
    // Ensure DATA_SIZE is large enough for 8*7 access pattern and loop iterations
    const int required_size = 8 * 8; // We access indices up to 8*7 in each iteration
    const int total_iterations = DATA_SIZE / required_size;

    // Initialize input and quantization buffers with non-zero test values
    for (int i = 0; i < DATA_SIZE; i++) {
        inbuf[i] = (JCOEF)(i % 256 - 128);
        quantbuf[i] = (ISLOW_MULT_TYPE)(i % 100 + 1); // avoid zero to prevent no-op mult
    }

    // Zero output workspace
    for (int i = 0; i < DATA_SIZE; i++) {
        wsbuf[i] = 0;
    }

    // Initialize pointers to start of buffers
    inptr = inbuf;
    quantptr = quantbuf;
    wsptr = wsbuf;

    // Reset counter
    ctr = 0;
}