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
    for (int j = 0; j < 4; j++)
        for (int k = 0; k < 4; k++)
            slice->block[4*j + k][0] = -2048;
}
