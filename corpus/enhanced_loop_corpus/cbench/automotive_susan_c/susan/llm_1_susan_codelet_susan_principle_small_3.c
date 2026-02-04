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
for (int idx = x_size + 1; idx < (y_size - 1) * x_size + (x_size - 1); idx++) {
    i = idx / x_size;
    j = idx % x_size;
    n = 100;
    p = in + (i - 1) * x_size + j - 1;
    cp = bp + in[i * x_size + j];
    n += *(cp - *p++);
    n += *(cp - *p++);
    n += *(cp - *p);
    p += x_size - 2;
    n += *(cp - *p);
    p += 2;
    n += *(cp - *p);
    p += x_size - 2;
    n += *(cp - *p++);
    n += *(cp - *p++);
    n += *(cp - *p);
    if (n <= max_no)
        r[i * x_size + j] = max_no - n;
}
}
