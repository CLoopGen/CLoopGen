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
for (i = 1; i < y_size - 1; i++) {
    int row_offset = i * x_size;
    for (j = 1; j < x_size - 1; j++) {
        n = 100;
        int center_idx = row_offset + j;
        int in_center_val = in[center_idx];
        cp = bp + in_center_val;

        // Use consecutive memory access via precomputed offsets
        int p_base = (i - 1) * x_size + (j - 1);
        const int offsets[] = {0, 1, 2, x_size, x_size + 2, 2*x_size, 2*x_size+1, 2*x_size+2};

        n += *(cp - in[p_base + offsets[0]]);
        n += *(cp - in[p_base + offsets[1]]);
        n += *(cp - in[p_base + offsets[2]]);
        n += *(cp - in[p_base + offsets[3]]);
        n += *(cp - in[p_base + offsets[4]]);
        n += *(cp - in[p_base + offsets[5]]);
        n += *(cp - in[p_base + offsets[6]]);
        n += *(cp - in[p_base + offsets[7]]);
        n += *(cp - in[p_base + offsets[8]]);

        if (n <= max_no)
            r[center_idx] = max_no - n;
    }
}
}
