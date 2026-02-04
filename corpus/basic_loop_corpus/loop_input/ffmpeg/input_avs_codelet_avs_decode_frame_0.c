#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int i;
int first;
int last;
uint32_t *pal;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB for ~0.01s runtime estimate

    buf = (uint8_t*)aligned_alloc(32, data_size + 6);
    if (!buf) exit(1);
    for (size_t k = 0; k < data_size + 6; k++) {
        buf[k] = (uint8_t)(k & 0xFF);
    }

    pal = (uint32_t*)aligned_alloc(32, data_size / 3 * sizeof(uint32_t));
    if (!pal) exit(1);
    for (int k = 0; k < (int)(data_size / 3); k++) {
        pal[k] = 0;
    }

    first = 0;
    last = (int)(data_size / 3);
}