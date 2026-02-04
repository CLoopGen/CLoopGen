#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    const int t0 = (((2841 * ptr[1 * 8] + 565 * ptr[7 * 8]) + 4) >> 3);
    const int t1 = (((565 * ptr[1 * 8] - 2841 * ptr[7 * 8]) + 4) >> 3);
    const int t2 = (((1609 * ptr[5 * 8] + 2408 * ptr[3 * 8]) + 4) >> 3);
    const int t3 = (((2408 * ptr[5 * 8] - 1609 * ptr[3 * 8]) + 4) >> 3);
    const int t4 = (((1108 * ptr[2 * 8] - 2676 * ptr[6 * 8]) + 4) >> 3);
    const int t5 = (((2676 * ptr[2 * 8] + 1108 * ptr[6 * 8]) + 4) >> 3);
    const int t6 = ((ptr[0 * 8] + ptr[4 * 8]) * (1 << 8)) + 8192;
    const int t7 = ((ptr[0 * 8] - ptr[4 * 8]) * (1 << 8)) + 8192;
    const int t8 = t0 + t2;
    const int t9 = t0 - t2;
    const int tA = (int)(181U * (t9 + (t1 - t3)) + 128) >> 8;
    const int tB = (int)(181U * (t9 - (t1 - t3)) + 128) >> 8;
    const int tC = t1 + t3;

    // Duplicate computation to increase arithmetic intensity
    const int tD = (((1609 * ptr[3 * 8] + 2408 * ptr[5 * 8]) + 4) >> 3); // swapped terms, same as t2 but re-computed
    const int tE = (tD + t1) >> 1;
    const int tF = (int)(181U * (tE + t0) + 128) >> 8;

    ptr[0 * 8] = (t6 + t5 + t8 + tF) >> 14;
    ptr[1 * 8] = (t7 + t4 + tA) >> 14;
    ptr[2 * 8] = (t7 - t4 + tB) >> 14;
    ptr[3 * 8] = (t6 - t5 + tC) >> 14;
    ptr[4 * 8] = (t6 - t5 - tC) >> 14;
    ptr[5 * 8] = (t7 - t4 + tB + tE) >> 14;
    ptr[6 * 8] = (t7 + t4 - tA) >> 14;
    ptr[7 * 8] = (t6 + t5 - t8) >> 14;

    ptr++;
}
}
