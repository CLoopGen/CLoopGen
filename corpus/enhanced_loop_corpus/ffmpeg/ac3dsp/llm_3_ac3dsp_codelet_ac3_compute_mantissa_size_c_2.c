#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint16_t ff_ac3_bap_bits[16];
extern uint16_t mant_cnt[6][16];
extern int blk;
extern int bap;
extern int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use indirect array indexing via a precomputed index map to modify access pattern
static const int indices[11] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; // Indirect access order
for (blk = 0; blk < 6; blk++) {
    bits += (mant_cnt[blk][1] / 3) * 5;
    bits += ((mant_cnt[blk][2] / 3) + (mant_cnt[blk][4] >> 1)) * 7;
    bits += mant_cnt[blk][3] * 3;
    for (bap = 0; bap < 11; bap++) {
        int idx = indices[bap]; // Indirect access through lookup
        bits += mant_cnt[blk][idx] * ff_ac3_bap_bits[idx];
    }
}
}
