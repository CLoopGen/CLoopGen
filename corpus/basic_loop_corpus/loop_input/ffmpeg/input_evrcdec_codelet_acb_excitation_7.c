#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *excitation;
float gain;
int length;
int i;

void init_vars() {
    length = 67108864; // ~256 MB of float data (67M elements * 4 bytes)
    excitation = (float*)aligned_alloc(32, length * sizeof(float));
    if (!excitation) {
        exit(1);
    }
    gain = 1.5f;
    for (i = 0; i < length; i++) {
        excitation[i] = (float)(i % 1000) / 100.0f;
    }
}