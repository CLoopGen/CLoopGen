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
        for (j = 1; j < x_size - 1; j++) {
            int local_n = 100;
            uchar *local_p = in + (i - 1) * x_size + j - 1;
            uchar *local_cp = bp + in[i * x_size + j];

            local_n += *(local_cp - local_p[0]);
            local_n += *(local_cp - local_p[1]);
            local_n += *(local_cp - local_p[2]);
            local_n += *(local_cp - local_p[x_size]);
            local_n += *(local_cp - local_p[x_size + 2]);
            local_n += *(local_cp - local_p[2*x_size]);
            local_n += *(local_cp - local_p[2*x_size + 1]);
            local_n += *(local_cp - local_p[2*x_size + 2]);

            if (local_n <= max_no)
                r[i * x_size + j] = max_no - local_n;
        }
    }
}
