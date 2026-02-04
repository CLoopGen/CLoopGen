#include <stdio.h>

typedef long BLASLONG;

float *b;
BLASLONG i;
BLASLONG ii;
float *ao1;
float *ao2;
float *ao3;
float *ao4;

static float b_array[256 * 1024];        // 1MB buffer for b
static float ao1_array[64 * 1024];      // 256KB for ao1
static float ao2_array[64 * 1024];      // 256KB for ao2
static float ao3_array[64 * 1024];      // 256KB for ao3
static float ao4_array[64 * 1024];      // 256KB for ao4

void init_vars() {
    b = b_array;
    ao1 = ao1_array;
    ao2 = ao2_array;
    ao3 = ao3_array;
    ao4 = ao4_array;
    
    // Each iteration consumes 2 floats from each aoX and writes 8 to b
    // Ensure we don't overflow any array: limited by smallest aoX array (64k floats = 32k pairs)
    // b can hold 256k/8 = 32k iterations
    i = 32000;  // This will process ~256KB of output, taking roughly 0.01-0.02s
    
    // Initialize array data to avoid undefined behavior
    for (int j = 0; j < 64 * 1024; j++) {
        ao1_array[j] = 1.0f + j * 0.001f;
        ao2_array[j] = 2.0f + j * 0.001f;
        ao3_array[j] = 3.0f + j * 0.001f;
        ao4_array[j] = 4.0f + j * 0.001f;
    }
    for (int j = 0; j < 256 * 1024; j++) {
        b_array[j] = 0.0f;
    }
}