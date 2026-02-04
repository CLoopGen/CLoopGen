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
    // Variant 2: Strided memory access pattern with transposed layout
    // Access memory with stride = n, simulating column-major traversal
    // Assume x is stored as two separate arrays: one for column 0 and one for column 1
    // i.e., x_col0[i] = x[i][0], x_col1[i] = x[i][1]
    int *x_col0 = &x[0][0];
    int *x_col1 = &x[0][1];

    accu0 = accu1 = accu2 = accu3 = 0;

    for (i = 0; i < n; i += 2) {
        // Strided access: jump by full row length to get same column across rows
        accu0 += (int64_t)x_col0[i + 0] * x_col0[i + 0];
        accu1 += (int64_t)x_col1[i + 0] * x_col1[i + 0];
        accu2 += (int64_t)x_col0[i + 1] * x_col0[i + 1];
        accu3 += (int64_t)x_col1[i + 1] * x_col1[i + 1];

        if ((accu0 | accu1 | accu2 | accu3) > (18446744073709551615UL - (-2147483647LL - 1) * (-2147483647LL - 1)) || i + 2 >= n) {
            accu0 >>= nz;
            accu1 >>= nz;
            accu2 >>= nz;
            accu3 >>= nz;

            // Replace original while loop with fixed unrolled behavior using for
            // Simulate up to 64 shifts (max bits in uint64_t)
            for (int k = 0; k < 64; k++) {
                if (((accu0 | accu1 | accu2 | accu3)) <= ((18446744073709551615UL - accu) >> 2)) break;
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
