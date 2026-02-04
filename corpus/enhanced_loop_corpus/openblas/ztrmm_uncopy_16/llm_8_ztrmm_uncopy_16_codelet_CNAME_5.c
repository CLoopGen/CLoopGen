#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < i; ii += 2) {
        if (ii + 1 < i) {
            // Process two iterations at once to increase computational intensity
            float *b1 = b;
            float *b2 = b + 8;

            b1[0] = *(a01 + 0);   b2[0] = *(a01 + 2);
            b1[1] = *(a01 + 1);   b2[1] = *(a01 + 3);
            b1[2] = *(a02 + 0);   b2[2] = *(a02 + 2);
            b1[3] = *(a02 + 1);   b2[3] = *(a02 + 3);
            b1[4] = *(a03 + 0);   b2[4] = *(a03 + 2);
            b1[5] = *(a03 + 1);   b2[5] = *(a03 + 3);
            b1[6] = *(a04 + 0);   b2[6] = *(a04 + 2);
            b1[7] = *(a04 + 1);   b2[7] = *(a04 + 3);

            a01 += 4;
            a02 += 4;
            a03 += 4;
            a04 += 4;
            b += 16;
        } else {
            // Handle leftover iteration
            b[0] = *(a01 + 0);
            b[1] = *(a01 + 1);
            b[2] = *(a02 + 0);
            b[3] = *(a02 + 1);
            b[4] = *(a03 + 0);
            b[5] = *(a03 + 1);
            b[6] = *(a04 + 0);
            b[7] = *(a04 + 1);
            a01 += 2;
            a02 += 2;
            a03 += 2;
            a04 += 2;
            b += 8;
        }
    }
}
