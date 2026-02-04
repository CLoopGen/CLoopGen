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
static size_t data_size = 16777216; // ~16MB to ensure loop runs long enough

RangeCoder *c;

void init_vars() {
    src_buffer = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    if (!src_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    c = (RangeCoder *)malloc(sizeof(RangeCoder));
    if (!c) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    c->src = src_buffer;
    c->src_end = src_buffer + data_size;
    c->range = 1;
    c->low = 0;
    c->got_error = 0;

    for (size_t i = 0; i < data_size; ++i) {
        src_buffer[i] = rand() & 0xFF;
    }
}