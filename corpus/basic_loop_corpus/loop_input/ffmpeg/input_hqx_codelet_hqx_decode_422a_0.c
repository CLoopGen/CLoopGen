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

static uint8_t global_buffer[1 << 20];
static uint8_t global_buffer_end[1];

HQXSlice *slice;
int i;

void init_vars() {
    slice = aligned_alloc(16, sizeof(HQXSlice));
    if (!slice) exit(1);

    slice->gb.buffer = global_buffer;
    slice->gb.buffer_end = global_buffer_end;
    slice->gb.index = 0;
    slice->gb.size_in_bits = 8 * (1 << 20);
    slice->gb.size_in_bits_plus8 = slice->gb.size_in_bits + 8;

    for (int j = 0; j < 16; j++) {
        for (int k = 0; k < 64; k++) {
            slice->block[j][k] = 0;
        }
    }

    i = 0;
}