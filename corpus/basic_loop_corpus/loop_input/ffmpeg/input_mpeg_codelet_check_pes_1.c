#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *p;
uint8_t *end;
static uint8_t *buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    buffer = (uint8_t *)aligned_alloc(32, data_size);
    if (!buffer) exit(1);

    // Initialize most of the data to 255, but break the sequence eventually
    for (size_t i = 0; i < data_size - 1; i++) {
        buffer[i] = 255;
    }
    buffer[data_size - 1] = 0; // Ensure loop stops before end

    p = buffer + 3;     // Initial p value after p += 3 in first loop step
    end = buffer + data_size;
}