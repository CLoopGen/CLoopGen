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
    if (mant_cnt[blk][1] >= 3) {
        bits += (mant_cnt[blk][1] / 3) * 5;
    }
    if (mant_cnt[blk][2] >= 3 || mant_cnt[blk][4] > 0) {
        bits += ((mant_cnt[blk][2] / 3) + (mant_cnt[blk][4] >> 1)) * 7;
    }
    if (mant_cnt[blk][3] > 0) {
        bits += mant_cnt[blk][3] * 3;
    }
    for (bap = 5; bap < 16; bap++) {
        if (mant_cnt[blk][bap] > 0 && ff_ac3_bap_bits[bap] > 0) {
            bits += mant_cnt[blk][bap] * ff_ac3_bap_bits[bap];
        }
    }
}
}
