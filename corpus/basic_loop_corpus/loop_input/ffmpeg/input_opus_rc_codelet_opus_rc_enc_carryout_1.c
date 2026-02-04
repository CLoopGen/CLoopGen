#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    int index;
    int size_in_bits;
    int size_in_bits_plus8;
} GetBitContext;

typedef struct RawBitsContext {
    const uint8_t *position;
    uint32_t bytes;
    uint32_t cachelen;
    uint32_t cacheval;
} RawBitsContext;

typedef struct OpusRangeCoder {
    GetBitContext gb;
    RawBitsContext rb;
    uint32_t range;
    uint32_t value;
    uint32_t total_bits;
    uint8_t buf[1287];
    uint8_t *rng_cur;
    int ext;
    int rem;
    int waste;
} OpusRangeCoder;

OpusRangeCoder *rc;
int mb;

void init_vars() {
    rc = malloc(sizeof(OpusRangeCoder));
    if (!rc) exit(1);

    rc->gb.buffer = NULL;
    rc->gb.buffer_end = NULL;
    rc->gb.index = 0;
    rc->gb.size_in_bits = 0;
    rc->gb.size_in_bits_plus8 = 0;

    rc->rb.position = NULL;
    rc->rb.bytes = 0;
    rc->rb.cachelen = 0;
    rc->rb.cacheval = 0;

    rc->range = 0;
    rc->value = 0;
    rc->total_bits = 0;

    rc->rng_cur = rc->buf;
    rc->ext = 25000000; // Adjusted to run loop ~25M times for ~0.01s duration
    rc->rem = 0;
    rc->waste = 0;

    mb = 42;
}