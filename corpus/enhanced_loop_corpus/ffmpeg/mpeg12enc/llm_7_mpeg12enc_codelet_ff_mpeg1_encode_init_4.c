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
        int prev_len = 0;
        for (mv = -(2 * 4096); mv <= (2 * 4096); mv++) {
            int len;
            if (mv == 0) {
                len = ff_mpeg12_mbMotionVectorTable[0][1];
            } else {
                int val, bit_size, code;
                bit_size = f_code - 1;
                val = mv;
                if (val < 0)
                    val = -val;
                val--;
                code = (val >> bit_size) + 1;
                if (code < 17)
                    len = ff_mpeg12_mbMotionVectorTable[code][1] + 1 + bit_size;
                else
                    len = ff_mpeg12_mbMotionVectorTable[16][1] + 2 + bit_size;
            }
            mv_penalty[f_code][mv + (2 * 4096)] = len + (prev_len & 0xFF);
            prev_len = len;
        }
    }
}
