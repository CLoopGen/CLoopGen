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



void loop(){
for (i = 7; i < y_size - 7; i++) {
    for (j = 7; j < x_size - 7; j++) {
        n = 100;
        int center_offset = i * x_size + j;
        p = in + (i - 3) * x_size + j - 1;
        cp = bp + in[center_offset];

        // Access pattern changed to use precomputed offsets for better locality and reduced pointer arithmetic
        const int stride = x_size;
        const int offsets[] = {
            0, 1, 2,
            stride - 3 + 0, stride - 3 + 1, stride - 3 + 2, stride - 3 + 3, stride - 3 + 4,
            2*stride - 5 + 0, 2*stride - 5 + 1, 2*stride - 5 + 2, 2*stride - 5 + 3, 2*stride - 5 + 4, 2*stride - 5 + 5, 2*stride - 5 + 6,
            3*stride - 6 + 0, 3*stride - 6 + 1, 3*stride - 6 + 2,
            3*stride - 4 + 0, 3*stride - 4 + 1, 3*stride - 4 + 2,
            4*stride - 6 + 0, 4*stride - 6 + 1, 4*stride - 6 + 2, 4*stride - 6 + 3, 4*stride - 6 + 4, 4*stride - 6 + 5, 4*stride - 6 + 6,
            5*stride - 5 + 0, 5*stride - 5 + 1, 5*stride - 5 + 2, 5*stride - 5 + 3, 5*stride - 5 + 4,
            6*stride - 3 + 0, 6*stride - 3 + 1, 6*stride - 3 + 2
        };
        const int num_offsets = 27;
        uchar *ptr = p;
        for (int k = 0; k < num_offsets; k++) {
            n += *(cp - ptr[offsets[k]]);
            if (n >= max_no) break;
        }
        if (n < max_no)
            r[center_offset] = max_no - n;
    }
}
}
