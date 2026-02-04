#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *samples;
int i;
int stereo;
int pred[2];

static int16_t *samples_buffer;

void init_vars() {
    stereo = 1; // ensures loop runs for i = 0 and i = 1
    pred[0] = 42;
    pred[1] = 84;

    size_t data_size = 16 * 1024 * 1024; // ~16MB of data to ensure sufficient runtime (~0.01 sec)
    samples_buffer = (int16_t*)aligned_alloc(32, data_size);
    if (!samples_buffer) {
        exit(1);
    }

    samples = samples_buffer;
}