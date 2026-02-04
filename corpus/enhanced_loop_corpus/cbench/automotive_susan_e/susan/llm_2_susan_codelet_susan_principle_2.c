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
    int base_offset = i * x_size;
    for (j = 3; j < x_size - 3; j++) {
        n = 100;
        int in_idx = base_offset + j;
        p = in + (i - 3) * x_size + j - 1;
        cp = bp + in[in_idx];
        // Access memory with consecutive pointer increments, unrolled fully
        n += *(cp - p[0]); 
        n += *(cp - p[1]); 
        n += *(cp - p[2]);
        n += *(cp - p[x_size - 1]); 
        n += *(cp - p[x_size]); 
        n += *(cp - p[x_size + 1]); 
        n += *(cp - p[x_size + 2]); 
        n += *(cp - p[x_size + 3]);
        n += *(cp - p[2*x_size - 1]); 
        n += *(cp - p[2*x_size]); 
        n += *(cp - p[2*x_size + 1]); 
        n += *(cp - p[2*x_size + 2]); 
        n += *(cp - p[2*x_size + 3]); 
        n += *(cp - p[2*x_size + 4]); 
        n += *(cp - p[2*x_size + 5]);
        n += *(cp - p[3*x_size - 1]); 
        n += *(cp - p[3*x_size]); 
        n += *(cp - p[3*x_size + 1]);
        n += *(cp - p[3*x_size + 3]); 
        n += *(cp - p[3*x_size + 4]); 
        n += *(cp - p[3*x_size + 5]);
        n += *(cp - p[4*x_size - 1]); 
        n += *(cp - p[4*x_size]); 
        n += *(cp - p[4*x_size + 1]); 
        n += *(cp - p[4*x_size + 2]); 
        n += *(cp - p[4*x_size + 3]); 
        n += *(cp - p[4*x_size + 4]); 
        n += *(cp - p[4*x_size + 5]);
        n += *(cp - p[5*x_size - 1]); 
        n += *(cp - p[5*x_size]); 
        n += *(cp - p[5*x_size + 1]); 
        n += *(cp - p[5*x_size + 2]); 
        n += *(cp - p[5*x_size + 3]);
        n += *(cp - p[6*x_size - 1]); 
        n += *(cp - p[6*x_size]); 
        n += *(cp - p[6*x_size + 1]);

        if (n <= max_no)
            r[base_offset + j] = max_no - n;
    }
}
}
