#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define BUFFER_LENGTH (DATA_SIZE_MB * 1024 * 1024 / sizeof(float) / 16)
#define IN_CHANNELS 16

float *ringbuffer;
int in_channels = IN_CHANNELS;
int buffer_length = BUFFER_LENGTH;
float *buffer[16];
int l;

void init_vars() {
    ringbuffer = aligned_alloc(32, IN_CHANNELS * BUFFER_LENGTH * sizeof(float));
    for (int i = 0; i < IN_CHANNELS; i++) {
        buffer[i] = NULL;
    }
    l = 0;
}