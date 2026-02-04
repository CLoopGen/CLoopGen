#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef int ISLOW_MULT_TYPE;

// Define all external variables
JLONG tmp0;
JLONG tmp1;
JLONG tmp2;
JLONG tmp3;
JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG tmp13;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;
JLONG z5;

#define DATA_SIZE (1 << 20)  // ~1MB of input data

static JCOEF in_buffer[DATA_SIZE * 8];
static ISLOW_MULT_TYPE quant_buffer[DATA_SIZE * 8];
static int ws_buffer[DATA_SIZE * 8];

JCOEFPTR inptr = in_buffer;
ISLOW_MULT_TYPE *quantptr = quant_buffer;
int *wsptr = ws_buffer;
int ctr;

void init_vars() {
    // Initialize input pointers to point into our buffers
    inptr = in_buffer;
    quantptr = quant_buffer;
    wsptr = ws_buffer;

    // Initialize in_buffer: ensure that most entries have non-zero high frequencies
    // to avoid the fast path, but some can take the fast path
    for (int i = 0; i < DATA_SIZE; i++) {
        in_buffer[i * 8 + 0] = (JCOEF)(320 + (i % 17));  // DC value
        in_buffer[i * 8 + 1] = (JCOEF)((i % 5) ? 1 : 0);
        in_buffer[i * 8 + 2] = (JCOEF)((i % 7) ? -2 : 0);
        in_buffer[i * 8 + 3] = (JCOEF)((i % 11) ? 1 : 0);
        in_buffer[i * 8 + 4] = (JCOEF)((i % 13) ? -1 : 0);
        in_buffer[i * 8 + 5] = (JCOEF)((i % 17) ? 2 : 0);
        in_buffer[i * 8 + 6] = (JCOEF)((i % 19) ? -1 : 0);
        in_buffer[i * 8 + 7] = (JCOEF)((i % 23) ? 1 : 0);
    }

    // Initialize quantization table with non-trivial values
    for (int i = 0; i < DATA_SIZE; i++) {
        quant_buffer[i * 8 + 0] = 8;
        quant_buffer[i * 8 + 1] = 13;
        quant_buffer[i * 8 + 2] = 10;
        quant_buffer[i * 8 + 3] = 14;
        quant_buffer[i * 8 + 4] = 16;
        quant_buffer[i * 8 + 5] = 24;
        quant_buffer[i * 8 + 6] = 20;
        quant_buffer[i * 8 + 7] = 28;
    }

    // Zero out workspace to avoid undefined behavior
    for (int i = 0; i < DATA_SIZE * 8; i++) {
        ws_buffer[i] = 0;
    }

    // Initialize loop counter
    ctr = 8;
}