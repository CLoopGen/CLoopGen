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
    // Variant 2: Consecutive 1D linearized access with pointer arithmetic to simulate 2D layout
    int16_t (*block)[64] = slice->block;
    int16_t *flat_start = &block[0][0];
    int offset;

    // Traverse all 16x64 elements but only set the first column equivalent (index 0, 64, 128, ...)
    for (offset = 0; offset < 16; offset++) {
        flat_start[offset * 64] = -2048;
    }
}
