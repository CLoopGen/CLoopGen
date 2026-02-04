#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int dx;
int w;
unsigned int asrc;
unsigned int tau;
int x;

uint8_t *dst_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64 MB for sufficient runtime (~0.01 sec target)
    dst_buffer = (uint8_t *)aligned_alloc(32, data_size);
    if (!dst_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        dst_buffer[i] = rand() & 0xFF;
    }

    dst = dst_buffer;
    dx = 1;
    w = (int)(data_size); 
    asrc = 0x400000U; 
    tau = 0x800000U; 
    x = 0;
}