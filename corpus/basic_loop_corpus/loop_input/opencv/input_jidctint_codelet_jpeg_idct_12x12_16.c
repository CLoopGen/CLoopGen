#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG tmp13;
JLONG tmp14;
JLONG tmp15;
JLONG tmp20;
JLONG tmp21;
JLONG tmp22;
JLONG tmp23;
JLONG tmp24;
JLONG tmp25;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;

short inbuf[64 * 32768]; // 128KB of input data (enough for ~0.01s runtime)
ISLOW_MULT_TYPE quantbuf[64 * 32768]; // Matching quantization table size
int wsbuf[64 * 32768]; // Workspace buffer

JCOEFPTR inptr = inbuf;
ISLOW_MULT_TYPE *quantptr = quantbuf;
int *wsptr = wsbuf;
int ctr;

void init_vars() {
    const int block_count = 32768; // Number of 8x8 blocks to process
    const int total_elements = block_count * 64;

    // Initialize input buffer with non-zero test pattern
    for (int i = 0; i < total_elements; i++) {
        inbuf[i] = (short)((i * 73) % 128 - 64);
    }

    // Initialize quantization table with realistic values
    for (int i = 0; i < total_elements; i++) {
        quantbuf[i] = (ISLOW_MULT_TYPE)((i * 101) % 255 + 1);
    }

    // Zero out workspace
    for (int i = 0; i < total_elements; i++) {
        wsbuf[i] = 0;
    }

    // Initialize pointers to start of buffers
    inptr = inbuf;
    quantptr = quantbuf;
    wsptr = wsbuf;
    ctr = 0;
}