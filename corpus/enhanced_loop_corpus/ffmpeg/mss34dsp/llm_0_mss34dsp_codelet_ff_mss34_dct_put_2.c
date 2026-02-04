#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 2; outer++) {
    for (i = 0; i < 4; i++) {
        const unsigned int t0 = -39409U * ptr[7 * 1] - 58980U * ptr[1 * 1];
        const unsigned int t1 = 39410U * ptr[1 * 1] - 58980U * ptr[7 * 1];
        const unsigned int t2 = -33410U * ptr[5 * 1] - 167963U * ptr[3 * 1];
        const unsigned int t3 = 33410U * ptr[3 * 1] - 167963U * ptr[5 * 1];
        const unsigned int t4 = ptr[3 * 1] + ptr[7 * 1];
        const unsigned int t5 = ptr[1 * 1] + ptr[5 * 1];
        const unsigned int t6 = 77062U * t4 + 51491U * t5;
        const unsigned int t7 = 77062U * t5 - 51491U * t4;
        const unsigned int t8 = 35470U * ptr[2 * 1] - 85623U * ptr[6 * 1];
        const unsigned int t9 = 35470U * ptr[6 * 1] + 85623U * ptr[2 * 1];
        const unsigned int tA = (((ptr[0 * 1] - ptr[4 * 1]) * (1U << 16)) + 8192);
        const unsigned int tB = (((ptr[0 * 1] + ptr[4 * 1]) * (1U << 16)) + 8192);
        ptr[0 * 1] = (int)(t1 + t6 + t9 + tB) >> 13;
        ptr[1 * 1] = (int)(t3 + t7 + t8 + tA) >> 13;
        ptr[2 * 1] = (int)(t2 + t6 - t8 + tA) >> 13;
        ptr[3 * 1] = (int)(t0 + t7 - t9 + tB) >> 13;
        ptr[4 * 1] = (int)(-(t0 + t7) - t9 + tB) >> 13;
        ptr[5 * 1] = (int)(-(t2 + t6) - t8 + tA) >> 13;
        ptr[6 * 1] = (int)(-(t3 + t7) + t8 + tA) >> 13;
        ptr[7 * 1] = (int)(-(t1 + t6) + t9 + tB) >> 13;
        ;
        ptr += 8;
    }
}
}
