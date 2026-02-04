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
    int row_offset = i * x_size;
    for (j = 7; j < x_size - 7; j++) {
        n = 100;
        int idx = row_offset + j;
        p = in + (i - 3) * x_size + j - 1;
        cp = bp + in[idx];
        
        // Unroll and access memory with consecutive pointer increments
        n += *(cp - p[0]);
        n += *(cp - p[1]);
        n += *(cp - p[2]);
        n += *(cp - p[x_size - 1]);
        n += *(cp - p[x_size]);
        n += *(cp - p[x_size + 1]);
        n += *(cp - p[x_size + 2]);
        n += *(cp - p[x_size + 3]);
        n += *(cp - p[2*x_size + 2]);
        n += *(cp - p[2*x_size + 3]);
        n += *(cp - p[2*x_size + 4]);
        n += *(cp - p[2*x_size + 5]);
        n += *(cp - p[2*x_size + 6]);
        n += *(cp - p[2*x_size + 7]);
        n += *(cp - p[2*x_size + 8]);
        n += *(cp - p[3*x_size + 8]);
        n += *(cp - p[3*x_size + 9]);
        n += *(cp - p[3*x_size + 10]);

        if (n >= max_no) continue;

        n += *(cp - p[3*x_size + 12]);
        if (n >= max_no) continue;

        n += *(cp - p[3*x_size + 13]);
        if (n >= max_no) continue;

        n += *(cp - p[3*x_size + 14]);
        if (n >= max_no) continue;

        n += *(cp - p[4*x_size + 14]);
        if (n >= max_no) continue;

        n += *(cp - p[4*x_size + 15]);
        if (n >= max_no) continue;

        n += *(cp - p[4*x_size + 16]);
        if (n >= max_no) continue;

        n += *(cp - p[4*x_size + 17]);
        if (n >= max_no) continue;

        n += *(cp - p[4*x_size + 18]);
        if (n >= max_no) continue;

        n += *(cp - p[4*x_size + 19]);
        if (n >= max_no) continue;

        n += *(cp - p[4*x_size + 20]);
        if (n >= max_no) continue;

        n += *(cp - p[5*x_size + 20]);
        if (n >= max_no) continue;

        n += *(cp - p[5*x_size + 21]);
        if (n >= max_no) continue;

        n += *(cp - p[5*x_size + 22]);
        if (n >= max_no) continue;

        n += *(cp - p[5*x_size + 23]);
        if (n >= max_no) continue;

        n += *(cp - p[5*x_size + 24]);
        if (n >= max_no) continue;

        n += *(cp - p[6*x_size + 24]);
        if (n >= max_no) continue;

        n += *(cp - p[6*x_size + 25]);
        if (n >= max_no) continue;

        n += *(cp - p[6*x_size + 26]);
        if (n >= max_no) continue;

        r[idx] = max_no - n;
    }
}
}
