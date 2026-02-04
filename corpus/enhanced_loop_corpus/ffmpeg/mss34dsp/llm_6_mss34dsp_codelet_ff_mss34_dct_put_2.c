#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const unsigned int t7_val = ptr[7 * 1];
    const unsigned int t1_val = ptr[1 * 1];
    const unsigned int t5_val = ptr[5 * 1];
    const unsigned int t3_val = ptr[3 * 1];
    const unsigned int t2_val = ptr[2 * 1];
    const unsigned int t6_val = ptr[6 * 1];
    const unsigned int t0_val = ptr[0 * 1];
    const unsigned int t4_val = ptr[4 * 1];

    const unsigned int t0 = -39409U * t7_val - 58980U * t1_val;
    const unsigned int t1 = 39410U * t1_val - 58980U * t7_val;
    const unsigned int t2 = -33410U * t5_val - 167963U * t3_val;
    const unsigned int t3 = 33410U * t3_val - 167963U * t5_val;
    const unsigned int t4 = t3_val + t7_val;
    const unsigned int t5 = t1_val + t5_val;
    const unsigned int t6 = 77062U * t4 + 51491U * t5;
    const unsigned int t7 = 77062U * t5 - 51491U * t4;
    const unsigned int t8 = 35470U * t2_val - 85623U * t6_val;
    const unsigned int t9 = 35470U * t6_val + 85623U * t2_val;
    const unsigned int tA = (((t0_val - t4_val) * (1U << 16)) + 8192);
    const unsigned int tB = (((t0_val + t4_val) * (1U << 16)) + 8192);

    const int p0_new = (int)(t1 + t6 + t9 + tB) >> 13;
    const int p1_new = (int)(t3 + t7 + t8 + tA) >> 13;
    const int p2_new = (int)(t2 + t6 - t8 + tA) >> 13;
    const int p3_new = (int)(t0 + t7 - t9 + tB) >> 13;
    const int p4_new = (int)(-(t0 + t7) - t9 + tB) >> 13;
    const int p5_new = (int)(-(t2 + t6) - t8 + tA) >> 13;
    const int p6_new = (int)(-(t3 + t7) + t8 + tA) >> 13;
    const int p7_new = (int)(-(t1 + t6) + t9 + tB) >> 13;

    ptr[0 * 1] = p0_new;
    ptr[1 * 1] = p1_new;
    ptr[2 * 1] = p2_new;
    ptr[3 * 1] = p3_new;
    ptr[4 * 1] = p4_new;
    ptr[5 * 1] = p5_new;
    ptr[6 * 1] = p6_new;
    ptr[7 * 1] = p7_new;

    ptr += 8;
}
}
