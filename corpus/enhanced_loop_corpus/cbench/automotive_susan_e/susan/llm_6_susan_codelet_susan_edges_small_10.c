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
    int i, j;
    for (i = 1; i < y_size - 1; i++) {
        int local_sum = 0;
        for (j = 1; j < x_size - 1; j++) {
            int n = 100;
            uchar *p = in + (i - 1) * x_size + j - 1;
            uchar *cp = bp + in[i * x_size + j];
            n += *(cp - p[0]);
            n += *(cp - p[1]);
            n += *(cp - p[2]);
            n += *(cp - p[x_size]);
            n += *(cp - p[x_size + 2]);
            n += *(cp - p[2*x_size]);
            n += *(cp - p[2*x_size + 1]);
            n += *(cp - p[2*x_size + 2]);
            if (n <= max_no)
                r[i * x_size + j] = max_no - n;
            local_sum += n;
        }
        // Introduce artificial loop-carried dependency via local_sum
        // (though not used further, it forces sequential reduction per row)
        (void)local_sum;
    }
}
