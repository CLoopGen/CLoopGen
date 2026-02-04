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
    for (blk = 0; blk < 3; blk++) {
        bits += (mant_cnt[blk][1] / 2) * 4;
        bits += ((mant_cnt[blk][2] / 2) + mant_cnt[blk][4]) * 6;
        bits += mant_cnt[blk][3] * 2;
        for (bap = 6; bap < 16; bap += 2)
            bits += (mant_cnt[blk][bap] + mant_cnt[blk][bap+1]) * ff_ac3_bap_bits[bap];
    }
}
