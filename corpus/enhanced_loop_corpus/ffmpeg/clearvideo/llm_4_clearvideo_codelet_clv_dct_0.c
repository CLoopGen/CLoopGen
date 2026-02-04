#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; ++i) {
    if (ptr[1 * 1] >= 0) {
        const int t0 = 2841 * ptr[1 * 1] + 565 * ptr[7 * 1];
        const int t1 = 565 * ptr[1 * 1] - 2841 * ptr[7 * 1];
        const int t2 = 1609 * ptr[5 * 1] + 2408 * ptr[3 * 1];
        const int t3 = 2408 * ptr[5 * 1] - 1609 * ptr[3 * 1];
        const int t4 = 1108 * ptr[2 * 1] - 2676 * ptr[6 * 1];
        const int t5 = 2676 * ptr[2 * 1] + 1108 * ptr[6 * 1];
        const int t6 = ((ptr[0 * 1] + ptr[4 * 1]) * (1 << 11)) + 128;
        const int t7 = ((ptr[0 * 1] - ptr[4 * 1]) * (1 << 11)) + 128;
        const int t8 = t0 + t2;
        const int t9 = t0 - t2;
        const int tA = (int)(181U * (t9 + (t1 - t3)) + 128) >> 8;
        const int tB = (int)(181U * (t9 - (t1 - t3)) + 128) >> 8;
        const int tC = t1 + t3;
        ptr[0 * 1] = (t6 + t5 + t8) >> 8;
        ptr[1 * 1] = (t7 + t4 + tA) >> 8;
        ptr[2 * 1] = (t7 - t4 + tB) >> 8;
        ptr[3 * 1] = (t6 - t5 + tC) >> 8;
        ptr[4 * 1] = (t6 - t5 - tC) >> 8;
        ptr[5 * 1] = (t7 - t4 - tB) >> 8;
        ptr[6 * 1] = (t7 + t4 - tA) >> 8;
        ptr[7 * 1] = (t6 + t5 - t8) >> 8;
    } else {
        ptr[0 * 1] = 0;
        ptr[1 * 1] = 0;
        ptr[2 * 1] = 0;
        ptr[3 * 1] = 0;
        ptr[4 * 1] = 0;
        ptr[5 * 1] = 0;
        ptr[6 * 1] = 0;
        ptr[7 * 1] = 0;
    }
    ptr += 8;
}
}
