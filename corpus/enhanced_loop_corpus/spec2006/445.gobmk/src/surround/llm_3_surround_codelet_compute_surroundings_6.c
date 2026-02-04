#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern int m;
extern int n;
extern int surrounded;
extern char mf[400];
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process elements with a fixed stride across the mf and mn arrays
    // Simulate strided access by jumping in steps through the logical grid, still using nested loops but accessing non-consecutive indices
    int base = (19 + 2);
    int row_stride = (19 + 1);
    int step = 2; // Stride step size for both m and n dimensions

    surrounded = 1; // Assume surrounded unless proven otherwise

    for (m = 0; m < board_size; m += step) {
        for (n = 0; n < board_size; n += step) {
            int offset = base + m * row_stride + n;

            // Bounds check on simulated data access
            if (mf[offset]) {
                if (mn[offset] == 0) {
                    surrounded = 0;
                    goto exit_loops;
                } else if (mn[offset] == 2) {
                    surrounded = 2;
                }
            }
        }
    }

    // Final pass for remaining elements if step > 1 to ensure correctness
    if (step > 1) {
        for (m = 0; m < board_size; m++) {
            for (n = 0; n < board_size; n++) {
                int offset = base + m * row_stride + n;
                if ((m % step != 0 || n % step != 0) && mf[offset]) {
                    if (mn[offset] == 0) {
                        surrounded = 0;
                        goto exit_loops;
                    } else if (mn[offset] == 2) {
                        surrounded = 2;
                    }
                }
            }
        }
    }

exit_loops:;
}
