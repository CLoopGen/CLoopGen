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
for (i = 2; i < y_size - 2; i++)
    for (j = 2; j < x_size - 2; j++) {
        n = 100;
        p = in + (i - 2) * x_size + j;
        cp = bp + in[i * x_size + j];
        n += *(cp - *(p + 0));
        n += *(cp - *(p + 1));
        n += *(cp - *(p + 2));
        p += x_size;
        n += *(cp - *(p + 0));
        n += *(cp - *(p + 1));
        n += *(cp - *(p + 2));
        p += x_size;
        n += *(cp - *(p + 0));
        n += *(cp - *(p + 1));
        n += *(cp - *(p + 2));
        p += x_size;
        n += *(cp - *(p + 0));
        n += *(cp - *(p + 1));
        n += *(cp - *(p + 2));
        p += x_size;
        n += *(cp - *(p + 0));
        n += *(cp - *(p + 1));
        n += *(cp - *(p + 2));
        p += x_size;
        n += *(cp - *(p + 0));
        n += *(cp - *(p + 1));
        n += *(cp - *(p + 2));
        if (n <= max_no)
            r[i * x_size + j] = max_no - n;
    }
}
