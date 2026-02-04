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
    for (blk = 0; blk < 12; blk++) {
        int idx = blk % 6;
        bits += (mant_cnt[idx][1] / 4) * 6;
        bits += ((mant_cnt[idx][2] / 4) + (mant_cnt[idx][4] >> 2)) * 8;
        bits += mant_cnt[idx][3] * 4;
        bits += mant_cnt[idx][5] * ff_ac3_bap_bits[5];
        bits += mant_cnt[idx][7] * ff_ac3_bap_bits[7];
        bits += mant_cnt[idx][9] * ff_ac3_bap_bits[9];
        bits += mant_cnt[idx][11] * ff_ac3_bap_bits[11];
        bits += mant_cnt[idx][13] * ff_ac3_bap_bits[13];
        bits += mant_cnt[idx][15] * ff_ac3_bap_bits[15];
    }
}
