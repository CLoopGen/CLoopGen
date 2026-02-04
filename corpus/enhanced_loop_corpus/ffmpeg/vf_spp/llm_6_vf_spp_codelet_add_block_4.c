#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern int linesize;
extern  int16_t block[64];
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y++) {
        uint16_t temp0 = dst[0 + y * linesize] + block[0 + y * 8];
        uint16_t temp1 = dst[1 + y * linesize] + block[1 + y * 8];
        uint16_t temp2 = dst[2 + y * linesize] + block[2 + y * 8];
        uint16_t temp3 = dst[3 + y * linesize] + block[3 + y * 8];
        uint16_t temp4 = dst[4 + y * linesize] + block[4 + y * 8];
        uint16_t temp5 = dst[5 + y * linesize] + block[5 + y * 8];
        uint16_t temp6 = dst[6 + y * linesize] + block[6 + y * 8];
        uint16_t temp7 = dst[7 + y * linesize] + block[7 + y * 8];

        dst[0 + y * linesize] = temp0;
        dst[1 + y * linesize] = temp1;
        dst[2 + y * linesize] = temp2;
        dst[3 + y * linesize] = temp3;
        dst[4 + y * linesize] = temp4;
        dst[5 + y * linesize] = temp5;
        dst[6 + y * linesize] = temp6;
        dst[7 + y * linesize] = temp7;
    }
}
