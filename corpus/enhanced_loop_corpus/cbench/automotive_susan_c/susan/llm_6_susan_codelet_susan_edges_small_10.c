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
    int ii, jj;
    for (ii = 1; ii < y_size - 1; ii++) {
        for (jj = 1; jj < x_size - 1; jj++) {
            n = 100;
            p = in + (ii - 1) * x_size + jj - 1;
            cp = bp + in[ii * x_size + jj];
            int temp_n = n;
            temp_n += *(cp - p[0]);
            temp_n += *(cp - p[1]);
            temp_n += *(cp - p[2]);
            temp_n += *(cp - p[x_size - 2 + 2]);
            temp_n += *(cp - p[x_size - 2 + 4]);
            temp_n += *(cp - p[2*x_size - 4 + 4]);
            temp_n += *(cp - p[2*x_size - 4 + 5]);
            temp_n += *(cp - p[2*x_size - 4 + 6]);
            if (temp_n <= max_no)
                r[ii * x_size + jj] = max_no - temp_n;
        }
    }
}
