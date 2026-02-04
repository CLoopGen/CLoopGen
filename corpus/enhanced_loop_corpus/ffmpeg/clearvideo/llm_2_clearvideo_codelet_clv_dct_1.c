#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const int idx = i * 8;
    const int t0 = (((2841 * ptr[idx + 1] + 565 * ptr[idx + 7]) + 4) >> 3);
    const int t1 = (((565 * ptr[idx + 1] - 2841 * ptr[idx + 7]) + 4) >> 3);
    const int t2 = (((1609 * ptr[idx + 5] + 2408 * ptr[idx + 3]) + 4) >> 3);
    const int t3 = (((2408 * ptr[idx + 5] - 1609 * ptr[idx + 3]) + 4) >> 3);
    const int t4 = (((1108 * ptr[idx + 2] - 2676 * ptr[idx + 6]) + 4) >> 3);
    const int t5 = (((2676 * ptr[idx + 2] + 1108 * ptr[idx + 6]) + 4) >> 3);
    const int t6 = ((ptr[idx + 0] + ptr[idx + 4]) * (1 << 8)) + 8192;
    const int t7 = ((ptr[idx + 0] - ptr[idx + 4]) * (1 << 8)) + 8192;
    const int t8 = t0 + t2;
    const int t9 = t0 - t2;
    const int tA = (int)(181U * (t9 + (t1 - t3)) + 128) >> 8;
    const int tB = (int)(181U * (t9 - (t1 - t3)) + 128) >> 8;
    const int tC = t1 + t3;
    ptr[idx + 0] = (t6 + t5 + t8) >> 14;
    ptr[idx + 1] = (t7 + t4 + tA) >> 14;
    ptr[idx + 2] = (t7 - t4 + tB) >> 14;
    ptr[idx + 3] = (t6 - t5 + tC) >> 14;
    ptr[idx + 4] = (t6 - t5 - tC) >> 14;
    ptr[idx + 5] = (t7 - t4 - tB) >> 14;
    ptr[idx + 6] = (t7 + t4 - tA) >> 14;
    ptr[idx + 7] = (t6 + t5 - t8) >> 14;
    ;
}
}
