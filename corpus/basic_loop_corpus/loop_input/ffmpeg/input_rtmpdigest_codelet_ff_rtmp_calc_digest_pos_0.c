#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int off;
int i;
int digest_pos;

static uint8_t buf_data[1 << 20]; // 1MB buffer

void init_vars() {
    buf = buf_data;
    off = 0;
    i = 0;
    digest_pos = 0;

    for (size_t j = 0; j < sizeof(buf_data); j++) {
        buf_data[j] = rand() & 0xFF;
    }
}