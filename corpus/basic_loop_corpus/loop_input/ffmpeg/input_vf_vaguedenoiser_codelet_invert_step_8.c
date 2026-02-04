#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float synthesis_high[9] = {1.0f, 0.9f, 0.8f, 0.7f, 0.6f, 0.5f, 0.4f, 0.3f, 0.2f};

float *output;
float *temp;
int i;
int findex;

void init_vars() {
    const size_t base_size = 1 << 20; // 1MB base allocation size
    findex = base_size;

    temp = (float*)aligned_alloc(32, (findex + 11) * sizeof(float));
    output = (float*)aligned_alloc(32, (2 * (findex + 11) + 10) * sizeof(float));

    for (int j = 0; j < findex + 11; j++) {
        temp[j] = (float)(j % 100) * 0.01f;
    }

    const int output_offset_min = 2 * 8 - 13; // minimum index written: i starts at 8
    const int output_offset_max = 2 * (findex + 10) - 5; // maximum index when i = findex+10
    const int output_size = output_offset_max - output_offset_min + 1;

    // Ensure output is zero-initialized in the range we'll access
    for (int j = 0; j < output_size; j++) {
        output[j + output_offset_min] = 0.0f;
    }
}