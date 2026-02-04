#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern uchar *in;
extern int *r;
extern uchar *bp;
extern int max_no;
extern int x_size;
extern int y_size;
extern int n;
extern int i;
extern int j;
extern uchar *p;
extern uchar *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 7; i < y_size - 7; i++) {
        for (j = 7; j < x_size - 7; j++) {
            n = 100;
            p = in + (i - 3) * x_size + j - 1;
            uchar center_val = in[i * x_size + j]; // Eliminate redundant load, reduce memory dependency
            cp = bp + center_val;

            // Restructure pointer arithmetic to remove intermediate side effects on `p` until necessary
            // This introduces a different data access pattern and removes early modifications to `p`
            const int offsets[] = {
                0, 1, 2,                     // First row: -3 offset
                x_size - 1, 0, 1, 2, 3,       // Second row: -2 offset (relative after step)
                x_size - 4, 0, 1, 2, 3, 4, 5, // Third row: -1 offset
                x_size - 5, 0, 1,             // Fourth row: same row
                8,                           // Skip two, then add three values later
                x_size - 5, 0, 1, 2, 3,       // Fifth row: +1 offset
                x_size - 4, 0, 1, 2,          // Sixth row: +2 offset
            };
            int total_ops = 25;
            int op_idx = 0;
            int temp_p = (int)(p - in); // Use integer index instead of pointer to decouple pointer updates

            // Process first 13 accesses without conditional checks to create loop-carried dependence via `n`
            for (; op_idx < 13 && n < max_no; op_idx++) {
                int curr_offset = offsets[op_idx];
                if (op_idx == 3) temp_p += x_size - 3; // Simulate row jump manually
                else if (op_idx == 8) temp_p += x_size - 5;
                else if (op_idx == 14) temp_p += x_size - 6;
                else if (op_idx == 17) temp_p += 2; // Handle special skip
                n += *(cp - in[temp_p++]);
            }

            // Remaining operations with fine-grained checks
            for (; op_idx < total_ops && n < max_no; op_idx++) {
                if (op_idx == 17) temp_p += 2;
                if (op_idx == 18) temp_p += x_size - 6;
                else if (op_idx == 24) temp_p += x_size - 5;
                else if (op_idx == 30) temp_p += x_size - 3;
                n += *(cp - in[temp_p++]);
            }

            if (n < max_no) {
                r[i * x_size + j] = max_no - n;
            }
        }
    }
}
