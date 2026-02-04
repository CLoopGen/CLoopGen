#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii += 2) {
    if (ii + 1 < i) {
        // Unroll two iterations into one
        // First iteration
        b[0] = *(a01 + 0);
        b[1] = *(a01 + 1);
        b[2] = *(a01 + 2);
        b[3] = *(a01 + 3);
        b[4] = *(a01 + 4);
        b[5] = *(a01 + 5);
        b[6] = *(a01 + 6);
        b[7] = *(a01 + 7);
        a01 += lda;
        b += 8;
        // Second iteration
        b[0] = *(a01 + 0);
        b[1] = *(a01 + 1);
        b[2] = *(a01 + 2);
        b[3] = *(a01 + 3);
        b[4] = *(a01 + 4);
        b[5] = *(a01 + 5);
        b[6] = *(a01 + 6);
        b[7] = *(a01 + 7);
        a01 += lda;
        b += 8;
    } else {
        // Handle odd iteration count
        b[0] = *(a01 + 0);
        b[1] = *(a01 + 1);
        b[2] = *(a01 + 2);
        b[3] = *(a01 + 3);
        b[4] = *(a01 + 4);
        b[5] = *(a01 + 5);
        b[6] = *(a01 + 6);
        b[7] = *(a01 + 7);
        a01 += lda;
        b += 8;
    }
}
}
