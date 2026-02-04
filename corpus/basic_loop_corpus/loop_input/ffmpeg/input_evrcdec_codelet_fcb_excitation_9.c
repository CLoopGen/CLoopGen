#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *excitation;
float pitch_gain;
int pitch_lag;
int subframe_size;
int i;

void init_vars() {
    subframe_size = 1 << 20; // Approximately 1M elements for ~0.01 sec runtime
    pitch_lag = 40;
    pitch_gain = 0.8f;

    excitation = (float*)aligned_alloc(32, subframe_size * sizeof(float));
    for (int j = 0; j < subframe_size; j++) {
        excitation[j] = (float)(j % 100) * 0.01f;
    }
}