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
// Change memory access pattern to use indirect indexing via precomputed offsets
// This introduces a strided but cache-aware indirect access pattern
const int offsets[] = {
    -1, 0, 1,                  // first row: j-1, j, j+1 relative to (i-3,j)
    x_size-2, x_size-1, x_size, x_size+1, x_size+2,   // second row
    2*x_size-3, 2*x_size-2, 2*x_size-1, 2*x_size, 2*x_size+1, 2*x_size+2, 2*x_size+3, // third
    3*x_size-4, 3*x_size-3, 3*x_size-2,               // fourth
    3*x_size, 3*x_size+1, 3*x_size+2,                 // fifth
    4*x_size-4, 4*x_size-3, 4*x_size-2, 4*x_size-1, 4*x_size, 4*x_size+1, 4*x_size+2, // sixth
    5*x_size-3, 5*x_size-2, 5*x_size-1, 5*x_size, 5*x_size+1,   // seventh
    6*x_size-2, 6*x_size-1, 6*x_size                    // eighth
};
int total_offsets = 25;
int base_idx = 0;

for (i = 3; i < y_size - 3; i++) {
    for (j = 3; j < x_size - 3; j++) {
        n = 100;
        base_idx = (i - 3) * x_size + j - 1;
        int center_val = in[i * x_size + j];
        cp = bp + center_val;
        
        // Use indirect, precomputed offset array for non-consecutive accesses
        for (int k = 0; k < total_offsets; k++) {
            int idx = base_idx + offsets[k];
            n += *(cp - in[idx]);
        }

        if (n <= max_no)
            r[i * x_size + j] = max_no - n;
    }
}
}
