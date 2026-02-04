#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    // Break loop-carried dependency on `ptr` increment by using local accumulation
    int16_t temp_block[8];
    for (int j = 0; j < 8; j++) {
        temp_block[j] = ptr[j * 8];
    }

    // Recompute all values based on local copy to eliminate RAW hazards from prior iteration
    const int t0 = (((2841 * temp_block[1] + 565 * temp_block[7]) + 4) >> 3);
    const int t1 = (((565 * temp_block[1] - 2841 * temp_block[7]) + 4) >> 3);
    const int t2 = (((1609 * temp_block[5] + 2408 * temp_block[3]) + 4) >> 3);
    const int t3 = (((2408 * temp_block[5] - 1609 * temp_block[3]) + 4) >> 3);
    const int t4 = (((1108 * temp_block[2] - 2676 * temp_block[6]) + 4) >> 3);
    const int t5 = (((2676 * temp_block[2] + 1108 * temp_block[6]) + 4) >> 3);
    const int t6 = ((temp_block[0] + temp_block[4]) * (1 << 8)) + 8192;
    const int t7 = ((temp_block[0] - temp_block[4]) * (1 << 8)) + 8192;
    const int t8 = t0 + t2;
    const int t9 = t0 - t2;
    const int tA = (int)(181U * (t9 + (t1 - t3)) + 128) >> 8;
    const int tB = (int)(181U * (t9 - (t1 - t3)) + 128) >> 8;
    const int tC = t1 + t3;

    // Eliminate loop-carried dependency: update all outputs before writing back
    temp_block[0] = (t6 + t5 + t8) >> 14;
    temp_block[1] = (t7 + t4 + tA) >> 14;
    temp_block[2] = (t7 - t4 + tB) >> 14;
    temp_block[3] = (t6 - t5 + tC) >> 14;
    temp_block[4] = (t6 - t5 - tC) >> 14;
    temp_block[5] = (t7 - t4 - tB) >> 14;
    temp_block[6] = (t7 + t4 - tA) >> 14;
    temp_block[7] = (t6 + t5 - t8) >> 14;

    // Write entire block at once — reduces intermediate memory dependencies
    for (int j = 0; j < 8; j++) {
        ptr[j * 8] = temp_block[j];
    }

    // Move pointer after full computation — strengthens independence between iterations
    ptr++;
}
}
