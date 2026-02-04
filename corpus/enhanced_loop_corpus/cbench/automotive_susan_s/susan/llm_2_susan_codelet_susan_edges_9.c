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
        int base_in_idx = (i - 3) * x_size + j - 1;
        p = in + base_in_idx;
        int in_val = in[row_offset + j];
        cp = bp + in_val;
        // Unroll and convert pointer arithmetic to indexed access for clarity and stride optimization
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; 
        p += x_size - 3;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; 
        p += x_size - 5;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; 
        p += x_size - 6;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; 
        p += 2;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; 
        p += x_size - 6;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; 
        p += x_size - 5;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; 
        p += x_size - 3;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; p++;
        n += cp[-p[0]]; 
        if (n <= max_no)
            r[row_offset + j] = max_no - n;
    }
}
}
