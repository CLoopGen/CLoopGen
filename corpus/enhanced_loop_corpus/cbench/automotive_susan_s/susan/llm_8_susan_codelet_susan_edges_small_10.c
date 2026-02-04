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
    // Variant 1: Increased computational intensity by unrolling the outer loop and adding extra arithmetic operations.
    // Also increased trip count slightly and added more neighbor contributions to increase complexity.
    for (i = 2; i < y_size - 2; i += 2) {
        for (j = 2; j < x_size - 2; j++) {
            n = 100;
            p = in + (i - 1) * x_size + j - 1;
            cp = bp + in[i * x_size + j];

            // Include all 8 neighbors with additional weight factors and extra arithmetic
            n += 2 * (*(cp - *p++)) + 1;
            n += 2 * (*(cp - *p++)) + 1;
            n += 2 * (*(cp - *p))   + 1; p++;
            n += 2 * (*(cp - *p))   + 1; p += x_size - 3;
            n += 2 * (*(cp - *p))   + 1; p++;
            n += 2 * (*(cp - *p))   + 1; p++;
            n += 2 * (*(cp - *p))   + 1; p += x_size - 3;
            n += 2 * (*(cp - *p++)) + 1;
            n += 2 * (*(cp - *p++)) + 1;
            n += 2 * (*(cp - *p))   + 1;

            // Additional diagonal contributions for higher computation
            n += *(cp - *(p - x_size - 2));
            n += *(cp - *(p + x_size + 0));

            if (n <= max_no)
                r[i * x_size + j] = max_no - n;

            // Second iteration of unrolled loop body (simulated unroll of i-loop)
            if (i + 1 < y_size - 2) {
                int idx = (i + 1) * x_size + j;
                n = 100;
                p = in + i * x_size + j - 1;
                cp = bp + in[idx];

                n += 2 * (*(cp - *p++)) + 1;
                n += 2 * (*(cp - *p++)) + 1;
                n += 2 * (*(cp - *p))   + 1; p++;
                n += 2 * (*(cp - *p))   + 1; p += x_size - 3;
                n += 2 * (*(cp - *p))   + 1; p++;
                n += 2 * (*(cp - *p))   + 1; p++;
                n += 2 * (*(cp - *p))   + 1; p += x_size - 3;
                n += 2 * (*(cp - *p++)) + 1;
                n += 2 * (*(cp - *p++)) + 1;
                n += 2 * (*(cp - *p))   + 1;

                n += *(cp - *(p - x_size - 2));
                n += *(cp - *(p + x_size + 0));

                if (n <= max_no)
                    r[idx] = max_no - n;
            }
        }
    }
}
