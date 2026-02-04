#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int bytes;
int i;
uint32_t c;
uint32_t *buf;
uint32_t *output;

void init_vars() {
    size_t data_size = 64 << 20; // 64 MB of data for sufficient runtime (~0.01 sec on modern CPU)
    bytes = data_size;

    buf = (uint32_t*)aligned_alloc(32, data_size);
    output = (uint32_t*)aligned_alloc(32, data_size);

    if (!buf || !output) {
        exit(1);
    }

    c = 0x12345678u;

    for (size_t j = 0; j < data_size / sizeof(uint32_t); j++) {
        buf[j] = (uint32_t)(j * 31);
    }

    i = 0;
}