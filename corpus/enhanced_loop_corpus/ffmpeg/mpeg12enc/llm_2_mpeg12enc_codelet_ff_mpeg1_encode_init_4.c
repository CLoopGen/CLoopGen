#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_mpeg12_mbMotionVectorTable[17][2];
extern uint8_t mv_penalty[8][16385];
extern int f_code;
extern int mv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int f_code = 1; f_code <= 7; f_code++) {
    uint8_t* penalty_row = &mv_penalty[f_code][0];
    const int base_offset = 2 * 4096;
    for (int mv_idx = 0; mv_idx <= 2 * 4096 * 2; mv_idx++) {
        int mv = mv_idx - base_offset;
        int len;
        if (mv == 0) {
            len = ff_mpeg12_mbMotionVectorTable[0][1];
        } else {
            int val = mv < 0 ? -mv : mv;
            int bit_size = f_code - 1;
            val--;
            int code = (val >> bit_size) + 1;
            if (code < 17) {
                len = ff_mpeg12_mbMotionVectorTable[code][1] + 1 + bit_size;
            } else {
                len = ff_mpeg12_mbMotionVectorTable[16][1] + 2 + bit_size;
            }
        }
        penalty_row[mv_idx] = len;
    }
}
}
