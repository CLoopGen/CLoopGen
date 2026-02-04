#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;
extern float *a05;
extern float *a06;
extern float *a07;
extern float *a08;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii += 2) {
    if (ii + 1 < i) {
        // Process two iterations at once to increase computational intensity
        float *b1 = b;
        float *b2 = b + 16;

        b1[0] = *(a01 + 0);   b2[0] = *(a01 + 2);
        b1[1] = *(a01 + 1);   b2[1] = *(a01 + 3);
        b1[2] = *(a02 + 0);   b2[2] = *(a02 + 2);
        b1[3] = *(a02 + 1);   b2[3] = *(a02 + 3);
        b1[4] = *(a03 + 0);   b2[4] = *(a03 + 2);
        b1[5] = *(a03 + 1);   b2[5] = *(a03 + 3);
        b1[6] = *(a04 + 0);   b2[6] = *(a04 + 2);
        b1[7] = *(a04 + 1);   b2[7] = *(a04 + 3);
        b1[8] = *(a05 + 0);   b2[8] = *(a05 + 2);
        b1[9] = *(a05 + 1);   b2[9] = *(a05 + 3);
        b1[10] = *(a06 + 0);  b2[10] = *(a06 + 2);
        b1[11] = *(a06 + 1);  b2[11] = *(a06 + 3);
        b1[12] = *(a07 + 0);  b2[12] = *(a07 + 2);
        b1[13] = *(a07 + 1);  b2[13] = *(a07 + 3);
        b1[14] = *(a08 + 0);  b2[14] = *(a08 + 2);
        b1[15] = *(a08 + 1);  b2[15] = *(a08 + 3);

        a01 += 4;
        a02 += 4;
        a03 += 4;
        a04 += 4;
        a05 += 4;
        a06 += 4;
        a07 += 4;
        a08 += 4;
        b += 32;
    } else {
        // Final odd iteration
        b[0] = *(a01 + 0);
        b[1] = *(a01 + 1);
        b[2] = *(a02 + 0);
        b[3] = *(a02 + 1);
        b[4] = *(a03 + 0);
        b[5] = *(a03 + 1);
        b[6] = *(a04 + 0);
        b[7] = *(a04 + 1);
        b[8] = *(a05 + 0);
        b[9] = *(a05 + 1);
        b[10] = *(a06 + 0);
        b[11] = *(a06 + 1);
        b[12] = *(a07 + 0);
        b[13] = *(a07 + 1);
        b[14] = *(a08 + 0);
        b[15] = *(a08 + 1);

        a01 += 2;
        a02 += 2;
        a03 += 2;
        a04 += 2;
        a05 += 2;
        a06 += 2;
        a07 += 2;
        a08 += 2;
        b += 16;
    }
}
}
