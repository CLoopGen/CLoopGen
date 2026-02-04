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
for (f_code = 1; f_code <= 7; f_code++) {
    mv = -(2 * 4096);
    for (int block = 0; block < (4 * 4096 + 1); block += 64) {
        for (int step = 0; step < 64 && (mv + step) <= (2 * 4096); step++) {
            int abs_mv = mv + step;
            int len;
            if (abs_mv == 0) {
                len = ff_mpeg12_mbMotionVectorTable[0][1];
            } else {
                int val, bit_size, code;
                bit_size = f_code - 1;
                val = abs_mv;
                if (val < 0)
                    val = -val;
                val--;
                code = (val >> bit_size) + 1;
                if (code < 17)
                    len = ff_mpeg12_mbMotionVectorTable[code][1] + 1 + bit_size;
                else
                    len = ff_mpeg12_mbMotionVectorTable[16][1] + 2 + bit_size;
            }
            mv_penalty[f_code][abs_mv + (2 * 4096)] = len;
        }
        mv += 64;
    }
}
}
