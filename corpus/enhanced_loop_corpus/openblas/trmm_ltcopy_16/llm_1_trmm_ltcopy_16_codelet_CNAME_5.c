#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < i; ii++) {
        for (BLASLONG k = 0; k < 2; k++) {
            b[0 + k*2] = *(a01 + 0 + k*2);
            b[1 + k*2] = *(a01 + 1 + k*2);
            a01 += k == 0 ? 0 : lda - 2; // Adjust pointer only in second iteration
            b   += k == 0 ? 0 : 2;
        }
        a01 += lda - 2; // Restore and advance a01
        a02 += lda;
        a03 += lda;
        a04 += lda;
        b += 2; // Final adjustment
    }
}
