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



void loop(){
    // Variant 1: Consecutive Memory Access via Precomputed Indices
    // Instead of repeatedly calculating `p = in + (i-3)*x_size + j-1` and using pointer arithmetic,
    // we precompute a base index and access `in` using consecutive offsets for better cache locality.
    for (i = 3; i < y_size - 3; i++) {
        int base_idx = i * x_size + j;
        for (j = 3; j < x_size - 3; j++) {
            n = 100;
            base_idx = i * x_size + j;
            int in_base = (i - 3) * x_size + (j - 1);
            cp = bp + in[base_idx];

            // Flatten the 2D spatial access into a 1D offset array for sequential memory reads
            const int offsets[] = {
                0, 1, 2,           // row 0: +0, +1, +2
                x_size, x_size+1, x_size+2, x_size+3, x_size+4, // row 1
                2*x_size, 2*x_size+1, 2*x_size+2, 2*x_size+3, 2*x_size+4, 2*x_size+5, 2*x_size+6, // row 2
                3*x_size-1, 3*x_size, 3*x_size+1, // row 3 (middle)
                4*x_size-1, 4*x_size, 4*x_size+1, // row 4 (after middle)
                5*x_size, 5*x_size+1, 5*x_size+2, 5*x_size+3, 5*x_size+4, 5*x_size+5, 5*x_size+6, // row 5
                6*x_size, 6*x_size+1, 6*x_size+2, 6*x_size+3, 6*x_size+4, // row 6
                7*x_size, 7*x_size+1, 7*x_size+2  // row 7
            };
            const int num_offsets = 31;

            for (int k = 0; k < num_offsets; k++) {
                n += *(cp - in[in_base + offsets[k]]);
            }

            if (n <= max_no)
                r[base_idx] = max_no - n;
        }
    }
}
