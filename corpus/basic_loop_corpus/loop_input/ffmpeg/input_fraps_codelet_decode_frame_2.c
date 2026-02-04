#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t *buf;
unsigned int y;
uint32_t *pal;

void init_vars() {
    size_t pal_size = 256;
    size_t buf_size = pal_size * 4;

    pal = (uint32_t *)malloc(pal_size * sizeof(uint32_t));
    if (!pal) exit(1);

    buf = (uint8_t *)malloc(buf_size);
    if (!buf) exit(1);

    for (size_t i = 0; i < buf_size; i++) {
        buf[i] = rand() & 0xFF;
    }
}