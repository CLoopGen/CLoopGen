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

typedef struct HQXSlice {
    GetBitContext gb;
    int16_t block[16][64] __attribute__((aligned(16)));
} HQXSlice;

extern HQXSlice *slice;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access using a flattened view of the first column
    int16_t *base = &slice->block[0][0];
    int stride = 64; // Assuming row-major layout, next block starts after 64 elements
    for (i = 0; i < 12; i++) {
        *(base + i * stride) = -2048;
    }
}
