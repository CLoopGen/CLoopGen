#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i += 2) {
    const unsigned int t0a = -39409U * ptr[7 * 8] - 58980U * ptr[1 * 8];
    const unsigned int t1a = 39410U * ptr[1 * 8] - 58980U * ptr[7 * 8];
    const unsigned int t2a = -33410U * ptr[5 * 8] - 167963U * ptr[3 * 8];
    const unsigned int t3a = 33410U * ptr[3 * 8] - 167963U * ptr[5 * 8];
    const unsigned int t4a = ptr[3 * 8] + ptr[7 * 8];
    const unsigned int t5a = ptr[1 * 8] + ptr[5 * 8];
    const unsigned int t6a = 77062U * t4a + 51491U * t5a;
    const unsigned int t7a = 77062U * t5a - 51491U * t4a;
    const unsigned int t8a = 35470U * ptr[2 * 8] - 85623U * ptr[6 * 8];
    const unsigned int t9a = 35470U * ptr[6 * 8] + 85623U * ptr[2 * 8];
    const unsigned int tAa = (((ptr[0 * 8] - ptr[4 * 8]) + 32) * (1U << 16));
    const unsigned int tBa = (((ptr[0 * 8] + ptr[4 * 8]) + 32) * (1U << 16));

    // First update pass
    int temp0 = (int)(t1a + t6a + t9a + tBa) >> 22;
    int temp1 = (int)(t3a + t7a + t8a + tAa) >> 22;
    int temp2 = (int)(t2a + t6a - t8a + tAa) >> 22;
    int temp3 = (int)(t0a + t7a - t9a + tBa) >> 22;
    int temp4 = (int)(-(t0a + t7a) - t9a + tBa) >> 22;
    int temp5 = (int)(-(t2a + t6a) - t8a + tAa) >> 22;
    int temp6 = (int)(-(t3a + t7a) + t8a + tAa) >> 22;
    int temp7 = (int)(-(t1a + t6a) + t9a + tBa) >> 22;

    // Apply first store
    ptr[0 * 8] = temp0;
    ptr[1 * 8] = temp1;
    ptr[2 * 8] = temp2;
    ptr[3 * 8] = temp3;
    ptr[4 * 8] = temp4;
    ptr[5 * 8] = temp5;
    ptr[6 * 8] = temp6;
    ptr[7 * 8] = temp7;

    // Second iteration with updated values (unrolled)
    const unsigned int t0b = -39409U * ptr[7 * 8] - 58980U * ptr[1 * 8];
    const unsigned int t1b = 39410U * ptr[1 * 8] - 58980U * ptr[7 * 8];
    const unsigned int t2b = -33410U * ptr[5 * 8] - 167963U * ptr[3 * 8];
    const unsigned int t3b = 33410U * ptr[3 * 8] - 167963U * ptr[5 * 8];
    const unsigned int t4b = ptr[3 * 8] + ptr[7 * 8];
    const unsigned int t5b = ptr[1 * 8] + ptr[5 * 8];
    const unsigned int t6b = 77062U * t4b + 51491U * t5b;
    const unsigned int t7b = 77062U * t5b - 51491U * t4b;
    const unsigned int t8b = 35470U * ptr[2 * 8] - 85623U * ptr[6 * 8];
    const unsigned int t9b = 35470U * ptr[6 * 8] + 85623U * ptr[2 * 8];
    const unsigned int tAb = (((ptr[0 * 8] - ptr[4 * 8]) + 32) * (1U << 16));
    const unsigned int tBb = (((ptr[0 * 8] + ptr[4 * 8]) + 32) * (1U << 16));

    ptr[0 * 8] = (int)(t1b + t6b + t9b + tBb) >> 22;
    ptr[1 * 8] = (int)(t3b + t7b + t8b + tAb) >> 22;
    ptr[2 * 8] = (int)(t2b + t6b - t8b + tAb) >> 22;
    ptr[3 * 8] = (int)(t0b + t7b - t9b + tBb) >> 22;
    ptr[4 * 8] = (int)(-(t0b + t7b) - t9b + tBb) >> 22;
    ptr[5 * 8] = (int)(-(t2b + t6b) - t8b + tAb) >> 22;
    ptr[6 * 8] = (int)(-(t3b + t7b) + t8b + tAb) >> 22;
    ptr[7 * 8] = (int)(-(t1b + t6b) + t9b + tBb) >> 22;

    ptr++;
}
}
