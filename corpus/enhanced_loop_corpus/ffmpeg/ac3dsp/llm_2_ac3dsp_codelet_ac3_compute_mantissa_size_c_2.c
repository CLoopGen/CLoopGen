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
for (blk = 0; blk < 6; blk++) {
    int idx;
    // Change memory access pattern to strided by unrolling and grouping field accesses
    bits += (mant_cnt[blk][1] / 3) * 5;
    bits += (mant_cnt[blk][3]) * 3;
    bits += ((mant_cnt[blk][2] / 3) + (mant_cnt[blk][4] >> 1)) * 7;
    for (idx = 5; idx < 16; idx += 2) {
        bits += mant_cnt[blk][idx] * ff_ac3_bap_bits[idx];
        if (idx + 1 < 16) {
            bits += mant_cnt[blk][idx + 1] * ff_ac3_bap_bits[idx + 1];
        }
    }
}
}
