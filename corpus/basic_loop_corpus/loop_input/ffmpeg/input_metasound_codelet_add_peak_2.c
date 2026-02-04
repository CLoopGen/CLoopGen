#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
float *shape;
float ppc_gain;
float *speech;
int j;
int center;
float *shape_end;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of data for sufficient runtime (~0.01 sec)

static float *shape_buffer;
static float *speech_buffer;

void init_vars() {
    width = 8192;
    ppc_gain = 1.5f;
    center = 4096;

    // Allocate buffers
    shape_buffer = aligned_alloc(32, sizeof(float) * (width + 1));
    speech_buffer = aligned_alloc(32, sizeof(float) * (width + 8192));

    // Initialize pointers
    shape = shape_buffer;
    shape_end = shape_buffer + width;
    speech = speech_buffer + 4096; // Ensure j + center stays in bounds

    // Initialize array elements to prevent undefined behavior
    for (int i = 0; i < width; i++) {
        shape_buffer[i] = 1.0f / (i + 1);
    }
    for (int i = 0; i < width + 8192; i++) {
        speech_buffer[i] = 0.1f;
    }
}