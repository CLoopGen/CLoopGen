#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

typedef struct RangeCoder {
    int low;
    int range;
    int outstanding_count;
    int outstanding_byte;
    uint8_t zero_state[256];
    uint8_t one_state[256];
    uint8_t *bytestream_start;
    uint8_t *bytestream;
    uint8_t *bytestream_end;
    int overread;
} RangeCoder;

RangeCoder *c;
int factor;
int max_p;
int64_t one;
int64_t p;
int p8;
int i;

void init_vars() {
    c = (RangeCoder*)calloc(1, sizeof(RangeCoder));
    if (!c) exit(1);

    c->bytestream_start = (uint8_t*)malloc(16 << 20); // 16 MB
    if (!c->bytestream_start) exit(1);
    c->bytestream = c->bytestream_start;
    c->bytestream_end = c->bytestream_start + (16 << 20);
    c->overread = 0;

    factor = 300000;
    max_p = 200;
    one = (int64_t)1 << 31;

    for (int j = 0; j < 256; j++) {
        c->zero_state[j] = (uint8_t)(j * 0.7);
        c->one_state[j] = (uint8_t)(j * 0.9);
    }

    for (int j = 256 - max_p; j <= max_p; j++) {
        if (j >= 0 && j < 256)
            c->one_state[j] = 0;
    }
}