#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};

uint8_t *dst;
int dx;
int w;
unsigned int asrc;
unsigned int tau;
int x;

uint8_t *data_buffer;

void init_vars() {
    w = 131072; 
    dx = 2;
    asrc = 0x8000U;
    tau = 0x4000U;
    x = 0;

    size_t buffer_size = (size_t)w * (size_t)abs(dx);
    data_buffer = aligned_alloc(32, buffer_size);
    if (!data_buffer) {
        exit(1);
    }

    for (int i = 0; i < w; i++) {
        size_t offset = i * dx;
        ((uint16_t*)(data_buffer + offset))[0] = 0xFFFFU;
    }

    dst = data_buffer;
}