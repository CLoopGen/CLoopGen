#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    const unsigned int t0 = -39409U * ptr[7] - 58980U * ptr[1];
    const unsigned int t1 = 39410U * ptr[1] - 58980U * ptr[7];
    const unsigned int t2 = -33410U * ptr[5] - 167963U * ptr[3];
    const unsigned int t3 = 33410U * ptr[3] - 167963U * ptr[5];
    const unsigned int t4 = ptr[3] + ptr[7];
    const unsigned int t5 = ptr[1] + ptr[5];
    const unsigned int t6 = 77062U * t4 + 51491U * t5;
    const unsigned int t7 = 77062U * t5 - 51491U * t4;
    const unsigned int t8 = 35470U * ptr[2] - 85623U * ptr[6];
    const unsigned int t9 = 35470U * ptr[6] + 85623U * ptr[2];
    const unsigned int tA = (((ptr[0] - ptr[4]) * (1U << 16)) + 8192);
    const unsigned int tB = (((ptr[0] + ptr[4]) * (1U << 16)) + 8192);

    // Increased arithmetic intensity: additional intermediate computations
    const unsigned int u0 = (t1 + t6) >> 1;
    const unsigned int u1 = (t3 + t7) >> 1;
    const unsigned int u2 = (t2 + t6) >> 1;
    const unsigned int u3 = (t0 + t7) >> 1;

    ptr[0] = (int)(u0 + t9 + tB + 16384U) >> 14;
    ptr[1] = (int)(u1 + t8 + tA + 16384U) >> 14;
    ptr[2] = (int)(u2 - t8 + tA + 16384U) >> 14;
    ptr[3] = (int)(u3 - t9 + tB + 16384U) >> 14;
    ptr[4] = (int)(-(t0 + t7) - t9 + tB + 16384U) >> 14;
    ptr[5] = (int)(-(t2 + t6) - t8 + tA + 16384U) >> 14;
    ptr[6] = (int)(-(t3 + t7) + t8 + tA + 16384U) >> 14;
    ptr[7] = (int)(-(t1 + t6) + t9 + tB + 16384U) >> 14;

    ptr += 8;
}
}
