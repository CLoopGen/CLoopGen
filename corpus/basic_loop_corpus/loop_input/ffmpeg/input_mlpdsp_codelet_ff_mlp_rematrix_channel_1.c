#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE_MB 64
#define TOTAL_SAMPLES (DATA_SIZE_MB * (1 << 20) / sizeof(int32_t))

int32_t *samples;
int32_t *coeffs;
uint8_t *bypassed_lsbs;
int8_t *noise_buffer;
int _usr_index;
unsigned int dest_ch;
uint16_t blockpos;
unsigned int maxchan;
int matrix_noise_shift;
int access_unit_size_pow2;
int32_t mask;
unsigned int src_ch;
unsigned int i;
int index2;

void init_vars() {
    blockpos = 8192;
    maxchan = 7;
    dest_ch = 0;
    _usr_index = 0;
    matrix_noise_shift = 1;
    access_unit_size_pow2 = 16;
    mask = 0x3FFF;
    index2 = 1;

    size_t samples_size = (maxchan + 1) * blockpos * 8 * sizeof(int32_t);
    size_t coeffs_size = (maxchan + 1) * sizeof(int32_t);
    size_t bypassed_size = blockpos * 8 * sizeof(uint8_t);
    size_t noise_buffer_size = access_unit_size_pow2 * sizeof(int8_t);

    samples = aligned_alloc(32, samples_size);
    coeffs = aligned_alloc(32, coeffs_size);
    bypassed_lsbs = aligned_alloc(32, bypassed_size);
    noise_buffer = aligned_alloc(32, noise_buffer_size);

    for (size_t i = 0; i <= maxchan; i++) {
        coeffs[i] = (int32_t)(i + 1);
    }

    for (size_t i = 0; i < (maxchan + 1) * blockpos * 8; i++) {
        samples[i] = (int32_t)(i % 256);
    }

    for (size_t i = 0; i < blockpos * 8; i++) {
        bypassed_lsbs[i] = (uint8_t)(i % 128);
    }

    for (size_t i = 0; i < access_unit_size_pow2; i++) {
        noise_buffer[i] = (int8_t)((i % 256) - 128);
    }
}