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
for (i = 7; i < y_size - 7; i += 2) {
    for (j = 7; j < x_size - 7; j += 2) {
        n = 100;
        // Strided memory access: process every 2nd element to increase stride and test cache behavior
        int idx = i * x_size + j;
        p = in + (i - 3) * x_size + (j - 1);
        cp = bp + in[idx];

        // Use strided pointer updates with fixed increments mimicking original logic but skipping elements
        n += *(cp - p[0]);   p += 1;
        n += *(cp - p[1]);   p += 1;
        n += *(cp - p[0]);   p += x_size - 3;
        n += *(cp - p[0]);   p += 1;
        n += *(cp - p[0]);   p += 1;
        n += *(cp - p[0]);   p += 1;
        n += *(cp - p[0]);   p += 1;
        n += *(cp - p[0]);   p += x_size - 5;
        n += *(cp - p[0]);   p += 1;
        n += *(cp - p[0]);   p += 1;
        n += *(cp - p[0]);   p += 1;
        n += *(cp - p[0]);   p += 1;
        n += *(cp - p[0]);   p += 1;
        n += *(cp - p[0]);   p += 1;
        n += *(cp - p[0]);   p += x_size - 6;
        n += *(cp - p[0]);   p += 1;
        n += *(cp - p[0]);   p += 1;
        n += *(cp - p[0]);   p += 2;
        if (n < max_no) {
            n += *(cp - p[0]); p += 1;
            if (n < max_no) {
                n += *(cp - p[0]); p += 1;
                if (n < max_no) {
                    n += *(cp - p[0]); p += x_size - 6;
                    if (n < max_no) {
                        n += *(cp - p[0]); p += 1;
                        if (n < max_no) {
                            n += *(cp - p[0]); p += 1;
                            if (n < max_no) {
                                n += *(cp - p[0]); p += 1;
                                if (n < max_no) {
                                    n += *(cp - p[0]); p += 1;
                                    if (n < max_no) {
                                        n += *(cp - p[0]); p += 1;
                                        if (n < max_no) {
                                            n += *(cp - p[0]); p += 1;
                                            if (n < max_no) {
                                                n += *(cp - p[0]); p += x_size - 5;
                                                if (n < max_no) {
                                                    n += *(cp - p[0]); p += 1;
                                                    if (n < max_no) {
                                                        n += *(cp - p[0]); p += 1;
                                                        if (n < max_no) {
                                                            n += *(cp - p[0]); p += 1;
                                                            if (n < max_no) {
                                                                n += *(cp - p[0]); p += 1;
                                                                if (n < max_no) {
                                                                    n += *(cp - p[0]); p += x_size - 3;
                                                                    if (n < max_no) {
                                                                        n += *(cp - p[0]); p += 1;
                                                                        if (n < max_no) {
                                                                            n += *(cp - p[0]); p += 1;
                                                                            if (n < max_no) {
                                                                                n += *(cp - p[0]);
                                                                                if (n < max_no)
                                                                                    r[idx] = max_no - n;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
}
