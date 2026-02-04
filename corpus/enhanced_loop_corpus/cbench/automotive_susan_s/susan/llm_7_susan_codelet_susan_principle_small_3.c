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
    int i, j, n_val;
    int *r_ptr = r + x_size + 1; // r[1 * x_size + 1] as base pointer
    for (i = 1; i < y_size - 1; i++) {
        uchar *row_start_in = in + i * x_size;
        uchar *row_start_bp = bp + in[i * x_size]; // Base offset for current center row
        for (j = 1; j < x_size - 1; j++) {
            n_val = 100;
            uchar center = row_start_in[j];
            uchar *cp = bp + center;

            uchar *p_top = in + (i - 1) * x_size + j - 1;
            uchar *p_mid = in + i * x_size + j - 1;
            uchar *p_bot = in + (i + 1) * x_size + j - 1;

            n_val += *(cp - p_top[0]); n_val += *(cp - p_top[1]); n_val += *(cp - p_top[2]);
            n_val += *(cp - p_mid[0]);                   n_val += *(cp - p_mid[2]);
            n_val += *(cp - p_bot[0]); n_val += *(cp - p_bot[1]); n_val += *(cp - p_bot[2]);

            if (n_val <= max_no)
                *r_ptr = max_no - n_val;
            r_ptr++;
        }
        r_ptr += 2; // Skip edges between rows due to j loop bounds
    }
}
