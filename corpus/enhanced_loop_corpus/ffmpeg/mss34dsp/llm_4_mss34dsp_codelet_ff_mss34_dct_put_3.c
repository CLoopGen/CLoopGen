#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    if (i % 2 == 0) {
        const unsigned int t0 = -39409U * ptr[7 * 8] - 58980U * ptr[1 * 8];
        const unsigned int t1 = 39410U * ptr[1 * 8] - 58980U * ptr[7 * 8];
        const unsigned int t2 = -33410U * ptr[5 * 8] - 167963U * ptr[3 * 8];
        const unsigned int t3 = 33410U * ptr[3 * 8] - 167963U * ptr[5 * 8];
        const unsigned int t4 = ptr[3 * 8] + ptr[7 * 8];
        const unsigned int t5 = ptr[1 * 8] + ptr[5 * 8];
        const unsigned int t6 = 77062U * t4 + 51491U * t5;
        const unsigned int t7 = 77062U * t5 - 51491U * t4;
        const unsigned int t8 = 35470U * ptr[2 * 8] - 85623U * ptr[6 * 8];
        const unsigned int t9 = 35470U * ptr[6 * 8] + 85623U * ptr[2 * 8];
        const unsigned int tA = (((ptr[0 * 8] - ptr[4 * 8]) + 32) * (1U << 16));
        const unsigned int tB = (((ptr[0 * 8] + ptr[4 * 8]) + 32) * (1U << 16));
        ptr[0 * 8] = (int)(t1 + t6 + t9 + tB) >> 22;
        ptr[1 * 8] = (int)(t3 + t7 + t8 + tA) >> 22;
        ptr[2 * 8] = (int)(t2 + t6 - t8 + tA) >> 22;
        ptr[3 * 8] = (int)(t0 + t7 - t9 + tB) >> 22;
        ptr[4 * 8] = (int)(-(t0 + t7) - t9 + tB) >> 22;
        ptr[5 * 8] = (int)(-(t2 + t6) - t8 + tA) >> 22;
        ptr[6 * 8] = (int)(-(t3 + t7) + t8 + tA) >> 22;
        ptr[7 * 8] = (int)(-(t1 + t6) + t9 + tB) >> 22;
    } else {
        const unsigned int temp0 = ptr[0 * 8];
        const unsigned int temp4 = ptr[4 * 8];
        const unsigned int tA = (((temp0 - temp4) + 32) * (1U << 16));
        const unsigned int tB = (((temp0 + temp4) + 32) * (1U << 16));
        ptr[0 * 8] = (int)tB >> 22;
        ptr[4 * 8] = (int)tB >> 22;
    }
    ptr++;
}
}
