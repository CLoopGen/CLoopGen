#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float qmf_window[48];
unsigned int nIn;
float *pOut;
int i;
int j;
float *p1;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB of total input data

static float out_buffer[DATA_SIZE];
static float in_buffer[DATA_SIZE];

void init_vars() {
    // Initialize qmf_window with non-zero values to avoid optimization issues
    for (int idx = 0; idx < 48; idx++) {
        qmf_window[idx] = (float)(idx + 1) / 48.0f;
    }

    // Set nIn so that the outer loop processes approximately DATA_SIZE / 2 elements
    // Each iteration consumes 2 elements from p1 and produces 2 floats in pOut
    nIn = DATA_SIZE / 2;

    // Initialize buffers
    for (int idx = 0; idx < DATA_SIZE; idx++) {
        in_buffer[idx] = (float)(idx % 1000) / 1000.0f;
        out_buffer[idx] = 0.0f;
    }

    // Initialize pointers
    p1 = in_buffer;
    pOut = out_buffer;

    // Ensure no out-of-bounds access:
    // - p1 will be incremented by 2 each iteration, starting at in_buffer
    // - maximum p1 offset: in_buffer + nIn*2 = in_buffer + DATA_SIZE -> valid
    // - pOut similarly covers full output buffer
}