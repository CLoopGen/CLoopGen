#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *data;
int size;
int i;

static uint8_t *internal_data_buffer;

void init_vars() {
    size = 128 * 1024 * 1024; // 128 MB to target ~0.01 sec on modern CPUs
    internal_data_buffer = (uint8_t*)aligned_alloc(32, size);
    if (!internal_data_buffer) {
        exit(1);
    }
    data = internal_data_buffer;
    for (int j = 0; j < size; j++) {
        internal_data_buffer[j] = rand() & 0xFF;
    }
}

__attribute__((destructor))
static void cleanup() {
    if (internal_data_buffer) {
        free(internal_data_buffer);
    }
}