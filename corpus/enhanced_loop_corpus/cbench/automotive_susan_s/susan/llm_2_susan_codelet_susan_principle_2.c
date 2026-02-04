#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern uchar *in;
extern int *r;
extern uchar *bp;
extern int max_no;
extern int x_size;
extern int y_size;
extern int i;
extern int j;
extern int n;
extern uchar *p;
extern uchar *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access via Pointer Precomputation
    // Instead of recalculating 'p' with strided arithmetic, precompute base pointer and use consecutive offsets.
    // This improves cache locality by accessing memory in a more predictable pattern.

    for (i = 3; i < y_size - 3; i++) {
        int row_offset = i * x_size;
        for (j = 3; j < x_size - 3; j++) {
            n = 100;
            int center_idx = row_offset + j;
            p = in + center_idx - 3*x_size - 1;  // Start at (i-3, j-1)
            cp = bp + in[center_idx];

            // Flatten the access pattern into a fixed offset array relative to p
            const int offsets[] = {
                0, 1, 2,
                x_size - 3 + 0, x_size - 3 + 1, x_size - 3 + 2, x_size - 3 + 3, x_size - 3 + 4,
                2*x_size - 8 + 0, 2*x_size - 8 + 1, 2*x_size - 8 + 2, 2*x_size - 8 + 3, 2*x_size - 8 + 4, 2*x_size - 8 + 5, 2*x_size - 8 + 6,
                3*x_size - 14 + 0, 3*x_size - 14 + 1, 3*x_size - 14 + 2,
                3*x_size - 12 + 0, 3*x_size - 12 + 1, 3*x_size - 12 + 2,
                4*x_size - 18 + 0, 4*x_size - 18 + 1, 4*x_size - 18 + 2, 4*x_size - 18 + 3, 4*x_size - 18 + 4, 4*x_size - 18 + 5, 4*x_size - 18 + 6,
                5*x_size - 23 + 0, 5*x_size - 23 + 1, 5*x_size - 23 + 2, 5*x_size - 23 + 3, 5*x_size - 23 + 4,
                6*x_size - 26 + 0, 6*x_size - 26 + 1, 6*x_size - 26 + 2
            };
            int num_accesses = sizeof(offsets) / sizeof(offsets[0]);

            for (int k = 0; k < num_accesses; k++) {
                n += *(cp - p[offsets[k]]);
            }

            if (n <= max_no)
                r[center_idx] = max_no - n;
        }
    }
}
