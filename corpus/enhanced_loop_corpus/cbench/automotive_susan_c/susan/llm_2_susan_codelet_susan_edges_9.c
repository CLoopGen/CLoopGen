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
for (i = 3; i < y_size - 3; i++) {
    int row_offset = i * x_size;
    for (j = 3; j < x_size - 3; j++) {
        n = 100;
        int base_idx = (i - 3) * x_size + j - 1;
        p = in + base_idx;
        uchar center_val = in[row_offset + j];
        cp = bp + center_val;

        // Unroll and convert pointer increments into indexed access for consecutive memory reads
        n += *(cp - p[0]);
        n += *(cp - p[1]);
        n += *(cp - p[2]);
        
        base_idx += x_size - 3;
        p = in + base_idx;
        n += *(cp - p[0]);
        n += *(cp - p[1]);
        n += *(cp - p[2]);
        n += *(cp - p[3]);
        n += *(cp - p[4]);

        base_idx += x_size - 5;
        p = in + base_idx;
        n += *(cp - p[0]);
        n += *(cp - p[1]);
        n += *(cp - p[2]);
        n += *(cp - p[3]);
        n += *(cp - p[4]);
        n += *(cp - p[5]);
        n += *(cp - p[6]);

        base_idx += x_size - 6;
        p = in + base_idx;
        n += *(cp - p[0]);
        n += *(cp - p[1]);
        n += *(cp - p[2]);

        base_idx += 2;
        p = in + base_idx;
        n += *(cp - p[0]);
        n += *(cp - p[1]);
        n += *(cp - p[2]);

        base_idx += x_size - 6;
        p = in + base_idx;
        n += *(cp - p[0]);
        n += *(cp - p[1]);
        n += *(cp - p[2]);
        n += *(cp - p[3]);
        n += *(cp - p[4]);
        n += *(cp - p[5]);
        n += *(cp - p[6]);

        base_idx += x_size - 5;
        p = in + base_idx;
        n += *(cp - p[0]);
        n += *(cp - p[1]);
        n += *(cp - p[2]);
        n += *(cp - p[3]);
        n += *(cp - p[4]);

        base_idx += x_size - 3;
        p = in + base_idx;
        n += *(cp - p[0]);
        n += *(cp - p[1]);
        n += *(cp - p[2]);

        if (n <= max_no)
            r[row_offset + j] = max_no - n;
    }
}
}
