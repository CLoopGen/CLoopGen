#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define FILTER_TAPS 10
#define DATA_SIZE_MB 64
#define BUFFER_SIZE ((DATA_SIZE_MB * 1024 * 1024) / sizeof(float))

float *in;
float *filter_coeffs;
float *memory;
float *samples;
int buffer_length;
int i;
int j;

void init_vars() {
    buffer_length = BUFFER_SIZE;

    in = (float *)aligned_alloc(32, buffer_length * sizeof(float));
    samples = (float *)aligned_alloc(32, buffer_length * sizeof(float));
    filter_coeffs = (float *)aligned_alloc(32, FILTER_TAPS * sizeof(float));
    memory = (float *)aligned_alloc(32, FILTER_TAPS * sizeof(float));

    for (int idx = 0; idx < buffer_length; idx++) {
        in[idx] = (float)((rand() % 1000) / 100.0);
        samples[idx] = 0.0f;
    }

    for (int idx = 0; idx < FILTER_TAPS; idx++) {
        filter_coeffs[idx] = (float)((rand() % 200) / 100.0) - 1.0f;
        memory[idx] = 0.0f;
    }

    i = 0;
    j = 0;
}