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
    // Variant 1: Consecutive Memory Access via Local Array Buffering
    // Instead of random access into 'in' and 'bp', buffer neighborhood values to enable consecutive access patterns.
    for (i = 1; i < y_size - 1; i++) {
        int row_offset = i * x_size;
        for (j = 1; j < x_size - 1; j++) {
            n = 100;
            int center_idx = row_offset + j;
            uchar center_val = in[center_idx];
            cp = bp + center_val;

            // Load 3x3 neighborhood around (i,j) into local array for consecutive access
            uchar neighbors[9];
            int src_idx = (i - 1) * x_size + (j - 1);
            for (int k = 0; k < 9; k++) {
                neighbors[k] = in[src_idx + (k == 3 || k == 6 ? 1 : 0) + (k == 1 || k == 2 || k == 4 || k == 5 || k == 7 || k == 8 ? 1 : 0)];
                if (k == 2) src_idx += x_size - 2;
                else if (k == 5) src_idx += x_size - 2;
                else src_idx++;
            }

            // Now access neighbors consecutively
            const int* idx_map = (const int[]){0,1,2,5,8,7,6,3}; // Clockwise from top-left
            for (int k = 0; k < 8; k++) {
                n += *(cp - neighbors[idx_map[k]]);
            }

            if (n <= max_no)
                r[center_idx] = max_no - n;
        }
    }
}
