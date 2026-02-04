#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    unsigned int low;
    uint16_t range;
    int16_t counter;
    const uint8_t *bytestream;
    const uint8_t *bytestream_end;
    uint16_t contexts[22];
    int error;
    int overread;
} DiracArith;

static uint8_t *bytestream_data;
DiracArith *c;
int i;

void init_vars() {
    size_t data_size = 16777216; // 16 MB for ~0.01 sec runtime estimate

    bytestream_data = malloc(data_size);
    if (!bytestream_data) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    for (size_t j = 0; j < data_size; j++) {
        bytestream_data[j] = rand() & 0xFF;
    }

    c = malloc(sizeof(DiracArith));
    if (!c) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    c->low = 0x12345678;
    c->range = 0x1234;
    c->counter = 0;
    c->bytestream = bytestream_data;
    c->bytestream_end = bytestream_data + data_size;
    for (int j = 0; j < 22; j++) {
        c->contexts[j] = j * 100;
    }
    c->error = 0;
    c->overread = 0;

    i = 0;
}