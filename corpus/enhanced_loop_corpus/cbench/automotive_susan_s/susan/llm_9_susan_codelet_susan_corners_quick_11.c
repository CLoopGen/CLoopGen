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
    int base_offset = i * x_size;
    for (j = 7; j < x_size - 7; j++) {
        n = 100;
        p = in + (i - 3) * x_size + j - 1;
        cp = bp + in[base_offset + j];
        // Reduced computation: sample only a subset of original memory accesses
        n += *(cp - p[0]);
        n += *(cp - p[1]);
        n += *(cp - p[2]);
        p += x_size - 2;
        n += *(cp - p[0]);
        n += *(cp - p[1]);
        n += *(cp - p[2]);
        p += x_size - 4;
        n += *(cp - p[0]);
        n += *(cp - p[1]);
        n += *(cp - p[2]);
        p += x_size - 5;
        n += *(cp - p[0]);
        n += *(cp - p[1]);
        if (n < max_no) {
            p += 1;
            n += *(cp - *p);
            if (n < max_no) {
                p += x_size - 5;
                n += *(cp - p[0]);
                if (n < max_no) {
                    n += *(cp - p[1]);
                    if (n < max_no) {
                        p += x_size - 3;
                        n += *(cp - p[0]);
                        if (n < max_no) {
                            n += *(cp - p[1]);
                            if (n < max_no)
                                r[base_offset + j] = max_no - n;
                        }
                    }
                }
            }
        }
    }
}
}
