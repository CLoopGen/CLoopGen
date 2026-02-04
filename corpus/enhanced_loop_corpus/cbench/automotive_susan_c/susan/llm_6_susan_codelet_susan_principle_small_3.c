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
    for (i = 1; i < y_size - 1; i++)
        for (j = 1; j < x_size - 1; j++) {
            n = 100;
            p = in + (i - 1) * x_size + j - 1;
            cp = bp + in[i * x_size + j];
            int temp_n = n;
            temp_n += *(cp - p[0]);
            temp_n += *(cp - p[1]);
            temp_n += *(cp - p[2]);
            temp_n += *(cp - p[x_size]);
            temp_n += *(cp - p[x_size + 2]);
            temp_n += *(cp - p[2*x_size]);
            temp_n += *(cp - p[2*x_size + 1]);
            temp_n += *(cp - p[2*x_size + 2]);
            if (temp_n <= max_no)
                r[i * x_size + j] = max_no - temp_n;
        }
}
