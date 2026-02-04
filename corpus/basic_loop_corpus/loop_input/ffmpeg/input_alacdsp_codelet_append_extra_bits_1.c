#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *buffer[2];
int32_t *extra_bits_buffer[2];
int extra_bits;
int channels;
int nb_samples;
int i;
int ch;

void init_vars() {
    channels = 2;
    nb_samples = 16777216; // ~64 MB per buffer, total ~256 MB for all buffers
    extra_bits = 4;

    for (int ch = 0; ch < channels; ch++) {
        buffer[ch] = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
        extra_bits_buffer[ch] = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));

        for (int i = 0; i < nb_samples; i++) {
            buffer[ch][i] = rand() & 0xFFFFF;
            extra_bits_buffer[ch][i] = rand() & ((1 << extra_bits) - 1);
        }
    }
}