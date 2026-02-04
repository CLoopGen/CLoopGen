#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float analysis_low[9] = {
    0.1f, 0.2f, 0.3f, 0.4f, 0.5f,
    0.4f, 0.3f, 0.2f, 0.1f
};

float *input;
float *output;
int low_size;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB input/output arrays for sufficient workload
    low_size = (data_size / sizeof(float)) / 2 - 5; // ensures 2*i-14 to 2*i-6 stay in bounds

    input = (float*)aligned_alloc(32, data_size);
    output = (float*)aligned_alloc(32, data_size);

    for (int j = 0; j < data_size / sizeof(float); ++j) {
        input[j] = (float)(rand() % 100) / 100.0f;
        output[j] = 0.0f;
    }
}