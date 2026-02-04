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

extern OpusRangeCoder *rc;
extern  int mb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (rc->ext > 0) {
        do {
            *rc->rng_cur++ = mb;
        } while (--rc->ext > 0);
    }
}
