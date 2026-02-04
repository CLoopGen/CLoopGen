#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[64];
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int t0, t1, t2, t3, t4, t5, t6, t7;
    // Load all values first to remove write-read dependencies across blocks
    t0 = temp[8 * 0 + i];
    t1 = temp[8 * 1 + i];
    t2 = temp[8 * 2 + i];
    t3 = temp[8 * 3 + i];
    t4 = temp[8 * 4 + i];
    t5 = temp[8 * 5 + i];
    t6 = temp[8 * 6 + i];
    t7 = temp[8 * 7 + i];

    // First stage: adjacent pairs
    temp[8 * 0 + i] = t0 + t1;
    temp[8 * 1 + i] = t0 - t1;
    temp[8 * 2 + i] = t2 + t3;
    temp[8 * 3 + i] = t2 - t3;
    temp[8 * 4 + i] = t4 + t5;
    temp[8 * 5 + i] = t4 - t5;
    temp[8 * 6 + i] = t6 + t7;
    temp[8 * 7 + i] = t6 - t7;

    // Second stage: stride-2 combinations
    t0 = temp[8 * 0 + i];  // re-read after prior write
    t2 = temp[8 * 2 + i];
    t1 = temp[8 * 1 + i];
    t3 = temp[8 * 3 + i];
    t4 = temp[8 * 4 + i];
    t6 = temp[8 * 6 + i];
    t5 = temp[8 * 5 + i];
    t7 = temp[8 * 7 + i];

    temp[8 * 0 + i] = t0 + t2;
    temp[8 * 2 + i] = t0 - t2;
    temp[8 * 1 + i] = t1 + t3;
    temp[8 * 3 + i] = t1 - t3;
    temp[8 * 4 + i] = t4 + t6;
    temp[8 * 6 + i] = t4 - t6;
    temp[8 * 5 + i] = t5 + t7;
    temp[8 * 7 + i] = t5 - t7;

    // Accumulate sum using absolute differences via conditional-free abs
    int s0 = temp[8 * 0 + i], s1 = temp[8 * 1 + i], s2 = temp[8 * 2 + i], s3 = temp[8 * 3 + i];
    int s4 = temp[8 * 4 + i], s5 = temp[8 * 5 + i], s6 = temp[8 * 6 + i], s7 = temp[8 * 7 + i];

    sum += ((s0 + s4) >= 0 ? (s0 + s4) : -(s0 + s4)) + ((s0 - s4) >= 0 ? (s0 - s4) : -(s0 - s4));
    sum += ((s1 + s5) >= 0 ? (s1 + s5) : -(s1 + s5)) + ((s1 - s5) >= 0 ? (s1 - s5) : -(s1 - s5));
    sum += ((s2 + s6) >= 0 ? (s2 + s6) : -(s2 + s6)) + ((s2 - s6) >= 0 ? (s2 - s6) : -(s2 - s6));
    sum += ((s3 + s7) >= 0 ? (s3 + s7) : -(s3 + s7)) + ((s3 - s7) >= 0 ? (s3 - s7) : -(s3 - s7));
}
}
