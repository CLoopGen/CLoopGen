#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int (*x)[2];
extern int n;
extern uint64_t accu;
extern uint64_t accu0;
extern uint64_t accu1;
extern uint64_t accu2;
extern uint64_t accu3;
extern int i;
extern int nz;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access pattern
    // Instead of accessing x[i+0][0], x[i+0][1], x[i+1][0], x[i+1][1] in a scattered way,
    // we reorganize the computation to access elements consecutively by flattening the 2D index.
    // Assume x is a 2D array with dimensions [n][2], so x[i][j] maps to flat index i*2 + j.
    int *base = &x[0][0];  // Flatten the array for sequential access
    accu0 = accu1 = accu2 = accu3 = 0;

    for (i = 0; i < n; i += 2) {
        int idx0 = i * 2;           // x[i][0]
        int idx0_1 = idx0 + 1;      // x[i][1]
        int idx1 = (i + 1) * 2;     // x[i+1][0]
        int idx1_1 = idx1 + 1;      // x[i+1][1]

        accu0 += (int64_t)base[idx0] * base[idx0];
        accu1 += (int64_t)base[idx0_1] * base[idx0_1];
        accu2 += (int64_t)base[idx1] * base[idx1];
        accu3 += (int64_t)base[idx1_1] * base[idx1_1];

        if ((accu0 | accu1 | accu2 | accu3) > (18446744073709551615UL - (-2147483647LL - 1) * (-2147483647LL - 1)) || i + 2 >= n) {
            accu0 >>= nz;
            accu1 >>= nz;
            accu2 >>= nz;
            accu3 >>= nz;

            // Unroll the while loop into a bounded for loop to avoid 'while'
            for (int shift = 0; shift < 64 && ((accu0 | accu1 | accu2 | accu3) > ((18446744073709551615UL - accu) >> 2)); ++shift) {
                accu0 >>= 1;
                accu1 >>= 1;
                accu2 >>= 1;
                accu3 >>= 1;
                accu >>= 1;
                nz++;
            }

            accu += accu0 + accu1 + accu2 + accu3;
            accu0 = accu1 = accu2 = accu3 = 0;
        }
    }
}
