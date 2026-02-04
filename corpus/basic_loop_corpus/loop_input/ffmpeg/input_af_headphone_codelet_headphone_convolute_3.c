#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *ringbuffer;
int in_channels = 64;
int buffer_length = 4096;
float *buffer[64];
int l;

void init_vars() {
    size_t total_size = (size_t)in_channels * buffer_length * sizeof(float);
    ringbuffer = aligned_alloc(32, total_size);
    for (int i = 0; i < in_channels; i++) {
        buffer[i] = NULL;
    }
}