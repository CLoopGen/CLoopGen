#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int indices[] = {0, 1, 2, 3, 4, 5, 6, 7};
for (i = 0; i < 8; i++) {
    const int base = indices[i] * 8;
    const unsigned int t0 = -39409U * ptr[base + 7] - 58980U * ptr[base + 1];
    const unsigned int t1 = 39410U * ptr[base + 1] - 58980U * ptr[base + 7];
    const unsigned int t2 = -33410U * ptr[base + 5] - 167963U * ptr[base + 3];
    const unsigned int t3 = 33410U * ptr[base + 3] - 167963U * ptr[base + 5];
    const unsigned int t4 = ptr[base + 3] + ptr[base + 7];
    const unsigned int t5 = ptr[base + 1] + ptr[base + 5];
    const unsigned int t6 = 77062U * t4 + 51491U * t5;
    const unsigned int t7 = 77062U * t5 - 51491U * t4;
    const unsigned int t8 = 35470U * ptr[base + 2] - 85623U * ptr[base + 6];
    const unsigned int t9 = 35470U * ptr[base + 6] + 85623U * ptr[base + 2];
    const unsigned int tA = (((ptr[base + 0] - ptr[base + 4]) + 32) * (1U << 16));
    const unsigned int tB = (((ptr[base + 0] + ptr[base + 4]) + 32) * (1U << 16));
    ptr[base + 0] = (int)(t1 + t6 + t9 + tB) >> 22;
    ptr[base + 1] = (int)(t3 + t7 + t8 + tA) >> 22;
    ptr[base + 2] = (int)(t2 + t6 - t8 + tA) >> 22;
    ptr[base + 3] = (int)(t0 + t7 - t9 + tB) >> 22;
    ptr[base + 4] = (int)(-(t0 + t7) - t9 + tB) >> 22;
    ptr[base + 5] = (int)(-(t2 + t6) - t8 + tA) >> 22;
    ptr[base + 6] = (int)(-(t3 + t7) + t8 + tA) >> 22;
    ptr[base + 7] = (int)(-(t1 + t6) + t9 + tB) >> 22;
    ;
    ptr += 7;
}
}
