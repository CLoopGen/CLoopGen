#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    const int t0 = 2841 * ptr[1] + 565 * ptr[7];
    const int t1 = 565 * ptr[1] - 2841 * ptr[7];
    const int t2 = 1609 * ptr[5] + 2408 * ptr[3];
    const int t3 = 2408 * ptr[5] - 1609 * ptr[3];
    const int t4 = 1108 * ptr[2] - 2676 * ptr[6];
    const int t5 = 2676 * ptr[2] + 1108 * ptr[6];
    const int t6 = ((ptr[0] + ptr[4]) * (1 << 11)) + 128;
    const int t7 = ((ptr[0] - ptr[4]) * (1 << 11)) + 128;
    const int t8 = t0 + t2;
    const int t9 = t0 - t2;
    const int tA = (int)(181U * (t9 + (t1 - t3)) + 128) >> 8;
    const int tB = (int)(181U * (t9 - (t1 - t3)) + 128) >> 8;
    const int tC = t1 + t3;

    // Additional computational steps to increase arithmetic intensity
    const int tD = (tA + tB + tC) * 2;
    const int tE = (t8 - t9) * 3;
    const int tF = (t6 ^ t7) & 0xFFFF;
    const int tG = (tD - tE) + (tF << 1);

    ptr[0] = (t6 + t5 + t8 + tG) >> 8;
    ptr[1] = (t7 + t4 + tA + tD) >> 8;
    ptr[2] = (t7 - t4 + tB + tE) >> 8;
    ptr[3] = (t6 - t5 + tC + tF) >> 8;
    ptr[4] = (t6 - t5 - tC + tG) >> 8;
    ptr[5] = (t7 - t4 - tB + tD) >> 8;
    ptr[6] = (t7 + t4 - tA + tE) >> 8;
    ptr[7] = (t6 + t5 - t8 + tF) >> 8;

    ptr += 8;
}
}
