#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const int16_t *base_ptr = ptr;
    const int t0 = (((2841 * base_ptr[1 * 8] + 565 * base_ptr[7 * 8]) + 4) >> 3);
    const int t1 = (((565 * base_ptr[1 * 8] - 2841 * base_ptr[7 * 8]) + 4) >> 3);
    const int t2 = (((1609 * base_ptr[5 * 8] + 2408 * base_ptr[3 * 8]) + 4) >> 3);
    const int t3 = (((2408 * base_ptr[5 * 8] - 1609 * base_ptr[3 * 8]) + 4) >> 3);
    const int t4 = (((1108 * base_ptr[2 * 8] - 2676 * base_ptr[6 * 8]) + 4) >> 3);
    const int t5 = (((2676 * base_ptr[2 * 8] + 1108 * base_ptr[6 * 8]) + 4) >> 3);
    const int t6 = ((base_ptr[0 * 8] + base_ptr[4 * 8]) * (1 << 8)) + 8192;
    const int t7 = ((base_ptr[0 * 8] - base_ptr[4 * 8]) * (1 << 8)) + 8192;
    const int t8 = t0 + t2;
    const int t9 = t0 - t2;
    const int tA = (int)(181U * (t9 + (t1 - t3)) + 128) >> 8;
    const int tB = (int)(181U * (t9 - (t1 - t3)) + 128) >> 8;
    const int tC = t1 + t3;

    // Introduce artificial WAW and WAR dependencies by reordering and staging writes
    int out0, out1, out2, out3, out4, out5, out6, out7;
    out0 = (t6 + t5 + t8) >> 14;
    out1 = (t7 + t4 + tA) >> 14;
    out2 = (t7 - t4 + tB) >> 14;
    out3 = (t6 - t5 + tC) >> 14;
    out4 = (t6 - t5 - tC) >> 14;
    out5 = (t7 - t4 - tB) >> 14;
    out6 = (t7 + t4 - tA) >> 14;
    out7 = (t6 + t5 - t8) >> 14;

    // Sequential write-back introduces WAW dependency on previous iterations' stores
    ptr[0 * 8] = out0;
    ptr[1 * 8] = out1;
    ptr[2 * 8] = out2;
    ptr[3 * 8] = out3;
    ptr[4 * 8] = out4;
    ptr[5 * 8] = out5;
    ptr[6 * 8] = out6;
    ptr[7 * 8] = out7;

    ptr++;
}
}
