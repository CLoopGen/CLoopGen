#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
float *shape;
float ppc_gain;
float *speech;
int j;
float *shape_end;
int center;

#define DATA_SIZE (64 << 20) // ~64MB of data for sufficient runtime (~0.01 sec)

static float *shape_buffer;
static float *speech_buffer;

void init_vars() {
    // Set parameters
    width = 32768; // Must be even to simplify bounds
    center = 16384;
    ppc_gain = 1.5f;

    // Allocate shape buffer and set shape/shape_end
    shape_buffer = (float*)aligned_alloc(32, sizeof(float) * (width + 1));
    shape = shape_buffer;
    shape_end = shape_buffer + width;

    // Allocate speech buffer with padding: [center - width/2, center + (width+1)/2)
    int speech_size = width + 1 + 2 * center; // generous padding
    speech_buffer = (float*)aligned_alloc(32, sizeof(float) * speech_size);
    speech = speech_buffer + center - (-width / 2); // base so that j + center indexes correctly

    // Initialize arrays to avoid NaN or extreme values
    for (int i = 0; i < (width + 1); i++) {
        shape_buffer[i] = (float)(i + 1) / (width + 1);
    }
    for (int i = 0; i < speech_size; i++) {
        speech_buffer[i] = 0.0f;
    }

    // Ensure loop bounds are valid
    // j from -width/2 to (width+1)/2 - 1, and shape < shape_end ensures early exit
}