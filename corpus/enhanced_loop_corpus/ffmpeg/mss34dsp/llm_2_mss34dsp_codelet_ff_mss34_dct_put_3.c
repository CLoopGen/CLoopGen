#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const int offset = i * 8;
    const unsigned int t0 = -39409U * ptr[offset + 7] - 58980U * ptr[offset + 1];
    const unsigned int t1 = 39410U * ptr[offset + 1] - 58980U * ptr[offset + 7];
    const unsigned int t2 = -33410U * ptr[offset + 5] - 167963U * ptr[offset + 3];
    const unsigned int t3 = 33410U * ptr[offset + 3] - 167963U * ptr[offset + 5];
    const unsigned int t4 = ptr[offset + 3] + ptr[offset + 7];
    const unsigned int t5 = ptr[offset + 1] + ptr[offset + 5];
    const unsigned int t6 = 77062U * t4 + 51491U * t5;
    const unsigned int t7 = 77062U * t5 - 51491U * t4;
    const unsigned int t8 = 35470U * ptr[offset + 2] - 85623U * ptr[offset + 6];
    const unsigned int t9 = 35470U * ptr[offset + 6] + 85623U * ptr[offset + 2];
    const unsigned int tA = (((ptr[offset + 0] - ptr[offset + 4]) + 32) * (1U << 16));
    const unsigned int tB = (((ptr[offset + 0] + ptr[offset + 4]) + 32) * (1U << 16));
    ptr[offset + 0] = (int)(t1 + t6 + t9 + tB) >> 22;
    ptr[offset + 1] = (int)(t3 + t7 + t8 + tA) >> 22;
    ptr[offset + 2] = (int)(t2 + t6 - t8 + tA) >> 22;
    ptr[offset + 3] = (int)(t0 + t7 - t9 + tB) >> 22;
    ptr[offset + 4] = (int)(-(t0 + t7) - t9 + tB) >> 22;
    ptr[offset + 5] = (int)(-(t2 + t6) - t8 + tA) >> 22;
    ptr[offset + 6] = (int)(-(t3 + t7) + t8 + tA) >> 22;
    ptr[offset + 7] = (int)(-(t1 + t6) + t9 + tB) >> 22;
    ;
    ptr += 8;
}
}
