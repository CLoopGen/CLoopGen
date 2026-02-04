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
    int local_r, local_n, idx_in, idx_out;
    uchar *local_p, *local_cp;
    for (i = 3; i < y_size - 3; i++) {
        for (j = 3; j < x_size - 3; j++) {
            // Eliminate loop-carried dependencies by making all operations local
            idx_out = i * x_size + j;
            idx_in = in[idx_out];
            local_n = 100;
            local_p = in + (i - 3) * x_size + j - 1;
            local_cp = bp + idx_in;

            // Process each access with explicit indexing to avoid pointer aliasing issues
            local_n += *(local_cp - local_p[0]);
            local_n += *(local_cp - local_p[1]);
            local_n += *(local_cp - local_p[2]);

            local_p += x_size - 3;
            local_n += *(local_cp - local_p[0]);
            local_n += *(local_cp - local_p[1]);
            local_n += *(local_cp - local_p[2]);
            local_n += *(local_cp - local_p[3]);
            local_n += *(local_cp - local_p[4]);

            local_p += x_size - 5;
            local_n += *(local_cp - local_p[0]);
            local_n += *(local_cp - local_p[1]);
            local_n += *(local_cp - local_p[2]);
            local_n += *(local_cp - local_p[3]);
            local_n += *(local_cp - local_p[4]);
            local_n += *(local_cp - local_p[5]);
            local_n += *(local_cp - local_p[6]);

            local_p += x_size - 6;
            local_n += *(local_cp - local_p[0]);
            local_n += *(local_cp - local_p[1]);
            local_n += *(local_cp - local_p[2]);

            local_p += 2;
            local_n += *(local_cp - local_p[0]);
            local_n += *(local_cp - local_p[1]);
            local_n += *(local_cp - local_p[2]);

            local_p += x_size - 6;
            local_n += *(local_cp - local_p[0]);
            local_n += *(local_cp - local_p[1]);
            local_n += *(local_cp - local_p[2]);
            local_n += *(local_cp - local_p[3]);
            local_n += *(local_cp - local_p[4]);
            local_n += *(local_cp - local_p[5]);
            local_n += *(local_cp - local_p[6]);

            local_p += x_size - 5;
            local_n += *(local_cp - local_p[0]);
            local_n += *(local_cp - local_p[1]);
            local_n += *(local_cp - local_p[2]);
            local_n += *(local_cp - local_p[3]);
            local_n += *(local_cp - local_p[4]);

            local_p += x_size - 3;
            local_n += *(local_cp - local_p[0]);
            local_n += *(local_cp - local_p[1]);
            local_n += *(local_cp - local_p[2]);

            // Use computed value without interfering with global state during computation
            n = local_n;
            if (n <= max_no) {
                local_r = max_no - n;
                r[idx_out] = local_r;
            }
        }
    }
}
