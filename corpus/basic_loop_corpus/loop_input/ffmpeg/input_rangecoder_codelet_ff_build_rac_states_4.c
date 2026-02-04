#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
int i;

void init_vars() {
    c = (RangeCoder*)calloc(1, sizeof(RangeCoder));
    if (!c) exit(1);

    c->bytestream_start = (uint8_t*)malloc(1 << 20);
    if (!c->bytestream_start) exit(1);

    c->bytestream = c->bytestream_start;
    c->bytestream_end = c->bytestream_start + (1 << 20);
    c->overread = 0;

    for (int j = 0; j < 256; j++) {
        c->one_state[j] = j;
    }
}