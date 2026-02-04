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
    for (j = 7; j < x_size - 7; j++) {
        n = 100;
        int center_val = in[i * x_size + j];
        cp = bp + center_val;

        // Define fixed offset array for 3x3, 5x5, 7x7 pattern relative to (i-3, j-1)
        const int offsets[] = {
            -3*x_size -1, -3*x_size, -3*x_size +1,
            -2*x_size -1, -2*x_size, -2*x_size +1, -2*x_size +2, -2*x_size +3,
            -1*x_size +1, -1*x_size +2, -1*x_size +3, -1*x_size +4, -1*x_size +5, -1*x_size +6, -1*x_size +7,
            0*x_size +7, 0*x_size +8, 0*x_size +9,
            1*x_size +9, 1*x_size +10, 1*x_size +11,
            2*x_size +11, 2*x_size +12, 2*x_size +13, 2*x_size +14, 2*x_size +15, 2*x_size +16, 2*x_size +17,
            3*x_size +17, 3*x_size +18, 3*x_size +19,
            4*x_size +19, 4*x_size +20, 4*x_size +21, 4*x_size +22, 4*x_size +23,
            5*x_size +23, 5*x_size +24, 5*x_size +25, 5*x_size +26
        };
        int num_offsets = 36;
        p = in + (i - 3) * x_size + j - 1;

        int k;
        for (k = 0; k < num_offsets; k++) {
            n += *(cp - *(p + offsets[k]));
            if (n >= max_no) break;
        }

        if (n < max_no) {
            r[i * x_size + j] = max_no - n;
        }
    }
}
}
