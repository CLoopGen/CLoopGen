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
    for (i = 1; i < y_size - 1; i++) {
        int row_offset = i * x_size;
        for (j = 1; j < x_size - 1; j++) {
            n = 100;
            int center_idx = row_offset + j;
            int in_center_val = in[center_idx];
            cp = bp + in_center_val;
            int p_base = (i - 1) * x_size + (j - 1);

            // Access neighbors using direct index arithmetic to ensure consecutive memory access pattern
            n += *(cp - in[p_base]);
            n += *(cp - in[p_base + 1]);
            n += *(cp - in[p_base + 2]);
            n += *(cp - in[p_base + x_size]);
            n += *(cp - in[p_base + x_size + 2]);
            n += *(cp - in[p_base + 2*x_size]);
            n += *(cp - in[p_base + 2*x_size + 1]);
            n += *(cp - in[p_base + 2*x_size + 2]);

            if (n <= max_no)
                r[center_idx] = max_no - n;
        }
    }
}
