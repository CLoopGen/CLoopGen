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
    int base_in = i * x_size;
    for (j = 1; j < x_size - 1; j++) {
        n = 100;
        int offset = base_in + j;
        p = in + (i - 1) * x_size + j - 1;
        cp = bp + in[offset];
        // Unroll and reorganize memory accesses to use direct offsets instead of pointer arithmetic
        n += *(cp - p[0]);
        n += *(cp - p[1]);
        n += *(cp - p[2]);
        n += *(cp - p[x_size]);
        n += *(cp - p[x_size + 2]);
        n += *(cp - p[2*x_size]);
        n += *(cp - p[2*x_size + 1]);
        n += *(cp - p[2*x_size + 2]);
        if (n <= max_no)
            r[offset] = max_no - n;
    }
}
}
