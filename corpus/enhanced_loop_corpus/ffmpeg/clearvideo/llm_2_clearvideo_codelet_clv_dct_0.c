#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const int16_t *base_ptr = ptr + (i * 8); // Strided access: each iteration works on a block of 8 elements
    const int t0 = 2841 * base_ptr[1] + 565 * base_ptr[7];
    const int t1 = 565 * base_ptr[1] - 2841 * base_ptr[7];
    const int t2 = 1609 * base_ptr[5] + 2408 * base_ptr[3];
    const int t3 = 2408 * base_ptr[5] - 1609 * base_ptr[3];
    const int t4 = 1108 * base_ptr[2] - 2676 * base_ptr[6];
    const int t5 = 2676 * base_ptr[2] + 1108 * base_ptr[6];
    const int t6 = ((base_ptr[0] + base_ptr[4]) * (1 << 11)) + 128;
    const int t7 = ((base_ptr[0] - base_ptr[4]) * (1 << 11)) + 128;
    const int t8 = t0 + t2;
    const int t9 = t0 - t2;
    const int tA = (int)(181U * (t9 + (t1 - t3)) + 128) >> 8;
    const int tB = (int)(181U * (t9 - (t1 - t3)) + 128) >> 8;
    const int tC = t1 + t3;
    ((int16_t*)base_ptr)[0] = (t6 + t5 + t8) >> 8;
    ((int16_t*)base_ptr)[1] = (t7 + t4 + tA) >> 8;
    ((int16_t*)base_ptr)[2] = (t7 - t4 + tB) >> 8;
    ((int16_t*)base_ptr)[3] = (t6 - t5 + tC) >> 8;
    ((int16_t*)base_ptr)[4] = (t6 - t5 - tC) >> 8;
    ((int16_t*)base_ptr)[5] = (t7 - t4 - tB) >> 8;
    ((int16_t*)base_ptr)[6] = (t7 + t4 - tA) >> 8;
    ((int16_t*)base_ptr)[7] = (t6 + t5 - t8) >> 8;
}
ptr += 64; // Advance pointer by total processed elements after loop
}
