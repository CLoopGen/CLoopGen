#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
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

    // Introduce artificial WAW and WAR dependencies by reordering writes
    // and using temporary storage to break direct RAW dependencies.
    int temp[8];
    temp[0] = (t6 + t5 + t8) >> 8;
    temp[1] = (t7 + t4 + tA) >> 8;
    temp[2] = (t7 - t4 + tB) >> 8;
    temp[3] = (t6 - t5 + tC) >> 8;
    temp[4] = (t6 - t5 - tC) >> 8;
    temp[5] = (t7 - t4 - tB) >> 8;
    temp[6] = (t7 + t4 - tA) >> 8;
    temp[7] = (t6 + t5 - t8) >> 8;

    // Break loop-carried dependency on `ptr` update by delaying pointer advance
    ptr[0] = temp[0];
    ptr[1] = temp[1];
    ptr[2] = temp[2];
    ptr[3] = temp[3];
    ptr[4] = temp[4];
    ptr[5] = temp[5];
    ptr[6] = temp[6];
    ptr[7] = temp[7];

    ptr += 8;
}
}
