#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const int stride = 2;
    const unsigned int t0 = -39409U * ptr[7 * stride] - 58980U * ptr[1 * stride];
    const unsigned int t1 = 39410U * ptr[1 * stride] - 58980U * ptr[7 * stride];
    const unsigned int t2 = -33410U * ptr[5 * stride] - 167963U * ptr[3 * stride];
    const unsigned int t3 = 33410U * ptr[3 * stride] - 167963U * ptr[5 * stride];
    const unsigned int t4 = ptr[3 * stride] + ptr[7 * stride];
    const unsigned int t5 = ptr[1 * stride] + ptr[5 * stride];
    const unsigned int t6 = 77062U * t4 + 51491U * t5;
    const unsigned int t7 = 77062U * t5 - 51491U * t4;
    const unsigned int t8 = 35470U * ptr[2 * stride] - 85623U * ptr[6 * stride];
    const unsigned int t9 = 35470U * ptr[6 * stride] + 85623U * ptr[2 * stride];
    const unsigned int tA = (((ptr[0 * stride] - ptr[4 * stride]) * (1U << 16)) + 8192);
    const unsigned int tB = (((ptr[0 * stride] + ptr[4 * stride]) * (1U << 16)) + 8192);
    ptr[0 * stride] = (int)(t1 + t6 + t9 + tB) >> 13;
    ptr[1 * stride] = (int)(t3 + t7 + t8 + tA) >> 13;
    ptr[2 * stride] = (int)(t2 + t6 - t8 + tA) >> 13;
    ptr[3 * stride] = (int)(t0 + t7 - t9 + tB) >> 13;
    ptr[4 * stride] = (int)(-(t0 + t7) - t9 + tB) >> 13;
    ptr[5 * stride] = (int)(-(t2 + t6) - t8 + tA) >> 13;
    ptr[6 * stride] = (int)(-(t3 + t7) + t8 + tA) >> 13;
    ptr[7 * stride] = (int)(-(t1 + t6) + t9 + tB) >> 13;
    ;
    ptr += 8 * stride;
}
}
