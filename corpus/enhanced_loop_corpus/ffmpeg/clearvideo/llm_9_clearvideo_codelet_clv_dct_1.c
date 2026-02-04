#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: fewer operations, simplified logic, higher trip count unrolled partially
for (i = 0; i < 4; i += 2) {
    // First iteration of original body
    {
        const int t0 = (((2841 * ptr[1 * 8] + 565 * ptr[7 * 8]) + 4) >> 3);
        const int t1 = (((565 * ptr[1 * 8] - 2841 * ptr[7 * 8]) + 4) >> 3);
        const int t2 = (((1609 * ptr[5 * 8] + 2408 * ptr[3 * 8]) + 4) >> 3);
        const int t3 = (((2408 * ptr[5 * 8] - 1609 * ptr[3 * 8]) + 4) >> 3);
        const int t6 = ((ptr[0 * 8] + ptr[4 * 8]) * (1 << 8)) + 8192;
        const int t8 = t0 + t2;
        const int tC = t1 + t3;

        ptr[0 * 8] = (t6 + t8) >> 14;  // Approximate reduced version
        ptr[7 * 8] = (t6 - t8) >> 14;
        ptr[3 * 8] = (t6 + tC) >> 14;
        ptr[4 * 8] = (t6 - tC) >> 14;
    }

    ptr++;

    // Second iteration (simulated with offset)
    if (i + 1 < 4) {
        const int t0 = (((2841 * ptr[1 * 8] + 565 * ptr[7 * 8]) + 4) >> 3);
        const int t1 = (((565 * ptr[1 * 8] - 2841 * ptr[7 * 8]) + 4) >> 3);
        const int t2 = (((1609 * ptr[5 * 8] + 2408 * ptr[3 * 8]) + 4) >> 3);
        const int t3 = (((2408 * ptr[5 * 8] - 1609 * ptr[3 * 8]) + 4) >> 3);
        const int t6 = ((ptr[0 * 8] + ptr[4 * 8]) * (1 << 8)) + 8192;
        const int t8 = t0 + t2;
        const int tC = t1 + t3;

        ptr[0 * 8] = (t6 + t8) >> 14;
        ptr[7 * 8] = (t6 - t8) >> 14;
        ptr[3 * 8] = (t6 + tC) >> 14;
        ptr[4 * 8] = (t6 - tC) >> 14;
    }

    ptr++;
}
}
