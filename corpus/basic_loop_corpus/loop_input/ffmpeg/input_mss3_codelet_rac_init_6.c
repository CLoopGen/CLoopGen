#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct RangeCoder {
    const uint8_t *src;
    const uint8_t *src_end;
    uint32_t range;
    uint32_t low;
    int got_error;
} RangeCoder;

static uint8_t *src_buffer;
static RangeCoder c_instance;
RangeCoder *c = &c_instance;
int size;
int i;

void init_vars() {
    size = 64 * 1024 * 1024;  // 64 MB to target ~0.01 sec runtime on modern CPU

    src_buffer = (uint8_t *)malloc(size);
    if (!src_buffer) {
        c->got_error = 1;
        return;
    }

    for (int j = 0; j < size; j++) {
        src_buffer[j] = rand() & 0xFF;
    }

    c->src = src_buffer;
    c->src_end = src_buffer + size;
    c->range = 0x1000000;
    c->low = 0;
    c->got_error = 0;
}