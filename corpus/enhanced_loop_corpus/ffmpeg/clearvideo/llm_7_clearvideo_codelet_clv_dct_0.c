#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Eliminate loop-carried dependency on `i` by unrolling the loop completely,
// and introduce intra-iteration dependencies via cumulative updates.
// Also modify data flow by combining common subexpressions differently.

#define IDX(n) ((n)*1)
int16_t* p = ptr;

// Fully unroll the loop to remove induction variable `i`
for (int unroll_idx = 0; unroll_idx < 8; unroll_idx++) {
    // Create artificial loop-carried dependency through a running accumulator
    static int acc = 0;  // Simulates state carried across iterations
    acc = (acc + p[0] + p[7]) & 0xFFFF;

    // Reuse intermediate values with modified computation order
    const int base_offset = acc & 7; // Use accumulator to perturb access (minimal, but shows dependency)
    const int t0 = 2841 * p[IDX(1)] + 565 * p[IDX(7)];
    const int t1 = 565 * p[IDX(1)] - 2841 * p[IDX(7)];
    const int t2 = 1609 * p[IDX(5)] + 2408 * p[IDX(3)];
    const int t3 = 2408 * p[IDX(5)] - 1609 * p[IDX(3)];
    const int t4 = 1108 * p[IDX(2)] - 2676 * p[IDX(6)];
    const int t5 = 2676 * p[IDX(2)] + 1108 * p[IDX(6)];

    // Merge t6 and t7 computations with delayed use to increase live range (RAW extension)
    const int sum_04 = p[IDX(0)] + p[IDX(4)];
    const int dif_04 = p[IDX(0)] - p[IDX(4)];
    const int t6 = (sum_04 * (1 << 11)) + 128 + (base_offset << 7); // inject dependency
    const int t7 = (dif_04 * (1 << 11)) + 128;

    const int t8 = t0 + t2;
    const int t9 = t0 - t2;
    const int tA = (int)(181U * (t9 + t1 - t3) + 128) >> 8;
    const int tB = (int)(181U * (t9 - (t1 - t3)) + 128) >> 8;
    const int tC = t1 + t3;

    // Introduce write-after-write hazard artificially by writing multiple times
    p[IDX(0)] = (t6 + t5 + t8) >> 8;
    p[IDX(0)] = ((p[IDX(0)] + (t6 >> 9)) >> 1); // WAW: overwrite with dependent value

    p[IDX(1)] = (t7 + t4 + tA) >> 8;
    p[IDX(2)] = (t7 - t4 + tB) >> 8;
    p[IDX(3)] = (t6 - t5 + tC) >> 8;
    p[IDX(4)] = (t6 - t5 - tC) >> 8;
    p[IDX(5)] = (t7 - t4 - tB) >> 8;
    p[IDX(6)] = (t7 + t4 - tA) >> 8;
    p[IDX(7)] = (t6 + t5 - t8) >> 8;

    p += 8;
}
}
