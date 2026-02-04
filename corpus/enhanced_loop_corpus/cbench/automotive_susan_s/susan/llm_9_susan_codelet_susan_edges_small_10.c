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
    // Variant 2: Reduced computational intensity with simplified access pattern and fewer operations.
    // Decreased trip count and collapsed nested loops into a single loop with stride-based traversal.
    // Only processes every second pixel to reduce workload.

    int total_pixels = (y_size - 2) * (x_size - 2);
    for (int idx = 0; idx < total_pixels; idx += 2) {  // Stride of 2 to reduce work
        i = 1 + idx / (x_size - 2);
        j = 1 + idx % (x_size - 2);

        // Skip invalid indices due to striding
        if (i >= y_size - 1 || j >= x_size - 1) continue;

        n = 50;  // Reduced base value
        p = in + i * x_size + j;
        cp = bp + in[i * x_size + j];

        // Simplified: only use center and four direct neighbors with minimal pointer arithmetic
        n += *(cp - p[-1]);         // left
        n += *(cp - p[1]);          // right
        n += *(cp - p[-x_size]);    // up
        n += *(cp - p[x_size]);     // down

        // Lighter condition check
        if (n <= max_no)
            r[i * x_size + j] = (max_no - n) >> 1;  // Halve result to reflect reduced intensity
    }
}
