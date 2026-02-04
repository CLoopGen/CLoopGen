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
    int base_in = i * x_size;
    for (j = 7; j < x_size - 7; j++) {
        n = 100;
        int offset = base_in + j;
        p = in + (i - 3) * x_size + j - 1;
        cp = bp + in[offset];
        
        // Unroll and reorganize memory accesses into a more consecutive pattern using direct indexing
        const int strides[] = {0, 1, 2, x_size-3+0, x_size-3+1, x_size-3+2, x_size-3+3, x_size-3+4,
                               2*x_size-8+0, 2*x_size-8+1, 2*x_size-8+2, 2*x_size-8+3, 2*x_size-8+4, 2*x_size-8+5, 2*x_size-8+6,
                               3*x_size-14+0, 3*x_size-14+1, 3*x_size-14+2};
        const int count = 19;
        int k;
        for (k = 0; k < count && n < max_no; k++) {
            if (k == 8 || k == 15) p += x_size - 6;
            else if (k == 7) p += x_size - 5;
            else if (k == 6) p += x_size - 3;
            n += *(cp - p[strides[k]]);
            p++;
        }
        if (n < max_no)
            r[offset] = max_no - n;
    }
}
}
