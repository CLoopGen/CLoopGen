#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *bits;
unsigned int num;
unsigned int p;

static uint8_t *internal_bits_buffer = NULL;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime on modern CPUs

    internal_bits_buffer = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!internal_bits_buffer) {
        exit(1);
    }

    bits = internal_bits_buffer;
    num = (unsigned int)data_size;
    p = 0;
}