#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct VCR1Context {
    int delta[16];
    int offset[4];
} VCR1Context;

VCR1Context *a;
uint8_t *bytestream;
int i;

static VCR1Context a_storage;
static uint8_t *bytestream_storage;

void init_vars() {
    a = &a_storage;
    bytestream_storage = (uint8_t *)malloc(32);
    if (!bytestream_storage) {
        exit(1);
    }
    bytestream = bytestream_storage;
    for (int j = 0; j < 32; j++) {
        bytestream[j] = j % 251;
    }
    i = 0;
}