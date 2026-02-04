#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float **samples;
int len;
int i;
float front_mix;
float center_mix;
float surround_mix;

void init_vars() {
    // Set scalar values
    len = 8000000;  // Approximately 32MB of float data (8e6 * 5 * sizeof(float) ~ 160MB)
    front_mix = 0.8f;
    center_mix = 0.6f;
    surround_mix = 0.4f;

    // Allocate 5 row pointers
    samples = (float**)calloc(5, sizeof(float*));
    if (!samples) exit(1);

    // Allocate each row with 'len' floats
    for (int row = 0; row < 5; row++) {
        samples[row] = (float*)calloc(len, sizeof(float));
        if (!samples[row]) exit(1);
        // Initialize with non-zero values to make computation meaningful
        for (int col = 0; col < len; col++) {
            samples[row][col] = (float)(rand() % 100) / 100.0f;
        }
    }
}