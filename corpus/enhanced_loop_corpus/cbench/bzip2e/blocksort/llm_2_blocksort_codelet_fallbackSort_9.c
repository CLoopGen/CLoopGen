#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 nblock;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access via (nblock + 2*i), we precompute a base index and access consecutive entries
    UInt32 base_idx = nblock >> 5;
    int shift_nblock = nblock & 31;
    for (i = 0; i < 32; i++) {
        int offset = 2 * i;
        int bit_pos_0 = (shift_nblock + offset) & 31;
        int bit_pos_1 = (shift_nblock + offset + 1) & 31;
        int word_idx_0 = base_idx + ((shift_nblock + offset) >> 5);
        int word_idx_1 = base_idx + ((shift_nblock + offset + 1) >> 5);

        bhtab[word_idx_0] |= (1U << bit_pos_0);
        bhtab[word_idx_1] &= ~(1U << bit_pos_1);
    }
}
