#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int i;
uint8_t map2to8[4];

static uint8_t *buf_storage;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB
    buf_storage = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    if (!buf_storage) {
        exit(1);
    }
    buf = buf_storage;
    for (size_t j = 0; j < 4; j++) {
        map2to8[j] = 0;
    }
}