#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>

float period = 16.0f;
int width = 32;
float *shape;
float ppc_gain = 0.85f;
float *speech;
int len;
int i;
int j;
int center;

void init_vars() {
    len = 1 << 20; // Approximately 1M samples to target ~0.01 sec runtime

    // Allocate speech with padding to prevent out-of-bounds access
    int speech_size = len + width;
    speech = (float*)calloc(speech_size, sizeof(float));
    if (!speech) exit(1);

    // Allocate shape with enough elements: loop runs approximately (len / period) times,
    // each time consuming 'width' samples
    int shape_size = ((len + width/2) / width + 1) * width;
    shape = (float*)malloc(shape_size * sizeof(float));
    if (!shape) exit(1);

    // Initialize shape with a simple windowed sine pattern (avoiding math functions that may not be linked)
    for (int idx = 0; idx < shape_size; idx++) {
        float t = (float)idx / (float)width;
        // Use simple hardcoded pattern to avoid dependency on sinf or other math functions
        // This mimics a quarter sine wave repeated periodically
        float val = t - (int)t; // fractional part
        shape[idx] = 0.5f * (1.0f - (val < 0.5f ? 1.0f - 2.0f*val : 2.0f*(1.0f-val)));
    }

    period = 16.0f;
    ppc_gain = 0.85f;
    width = 32;
}