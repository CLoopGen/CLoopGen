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
// Strided memory access using precomputed offsets to simulate non-consecutive strides
int offset_pattern[] = {
    0, 1, 2,                    // First row: j-1, j, j+1
    x_size - 1, x_size, x_size+1, x_size+2, x_size+3,   // Second row
    2*x_size - 1, 2*x_size, 2*x_size+1, 2*x_size+2, 2*x_size+3, 2*x_size+4, 2*x_size+5,
    3*x_size - 1, 3*x_size, 3*x_size+1,
    3*x_size + 3, 3*x_size + 4, 3*x_size + 5,
    4*x_size - 1, 4*x_size, 4*x_size+1, 4*x_size+2, 4*x_size+3, 4*x_size+4, 4*x_size+5,
    5*x_size - 1, 5*x_size, 5*x_size+1, 5*x_size+2, 5*x_size+3,
    6*x_size - 1, 6*x_size, 6*x_size+1
};
int num_offsets = 34;

for (i = 3; i < y_size - 3; i++)
    for (j = 3; j < x_size - 3; j++) {
        n = 100;
        p = in + (i - 3) * x_size + j - 1;
        cp = bp + in[i * x_size + j];
        // Use strided access via offset array
        for (int k = 0; k < num_offsets; k++) {
            n += *(cp - p[offset_pattern[k]]);
        }
        if (n <= max_no)
            r[i * x_size + j] = max_no - n;
    }
}
