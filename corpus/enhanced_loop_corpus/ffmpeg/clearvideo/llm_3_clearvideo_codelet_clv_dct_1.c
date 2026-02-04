#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Strided access pattern: even then odd indices
for (i = 0; i < 8; i++) {
    const int base = indices[i] * 8;
    const int t0 = (((2841 * ptr[base + 1] + 565 * ptr[base + 7]) + 4) >> 3);
    const int t1 = (((565 * ptr[base + 1] - 2841 * ptr[base + 7]) + 4) >> 3);
    const int t2 = (((1609 * ptr[base + 5] + 2408 * ptr[base + 3]) + 4) >> 3);
    const int t3 = (((2408 * ptr[base + 5] - 1609 * ptr[base + 3]) + 4) >> 3);
    const int t4 = (((1108 * ptr[base + 2] - 2676 * ptr[base + 6]) + 4) >> 3);
    const int t5 = (((2676 * ptr[base + 2] + 1108 * ptr[base + 6]) + 4) >> 3);
    const int t6 = ((ptr[base + 0] + ptr[base + 4]) * (1 << 8)) + 8192;
    const int t7 = ((ptr[base + 0] - ptr[base + 4]) * (1 << 8)) + 8192;
    const int t8 = t0 + t2;
    const int t9 = t0 - t2;
    const int tA = (int)(181U * (t9 + (t1 - t3)) + 128) >> 8;
    const int tB = (int)(181U * (t9 - (t1 - t3)) + 128) >> 8;
    const int tC = t1 + t3;
    ptr[base + 0] = (t6 + t5 + t8) >> 14;
    ptr[base + 1] = (t7 + t4 + tA) >> 14;
    ptr[base + 2] = (t7 - t4 + tB) >> 14;
    ptr[base + 3] = (t6 - t5 + tC) >> 14;
    ptr[base + 4] = (t6 - t5 - tC) >> 14;
    ptr[base + 5] = (t7 - t4 - tB) >> 14;
    ptr[base + 6] = (t7 + t4 - tA) >> 14;
    ptr[base + 7] = (t6 + t5 - t8) >> 14;
    ;
}
}
