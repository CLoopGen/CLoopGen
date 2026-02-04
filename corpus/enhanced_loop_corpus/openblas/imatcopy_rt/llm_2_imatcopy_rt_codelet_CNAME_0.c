#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG rows;
extern BLASLONG cols;
extern float alpha;
extern float *a;
extern BLASLONG lda;
extern BLASLONG i;
extern BLASLONG j;
extern float *aptr;
extern float *bptr;
extern float tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < rows; i++) {
    bptr = &a[i * lda];  // Change to row-major base pointer with consistent stride
    bptr[0] = alpha * bptr[0];
    for (j = 1; j < cols - i; j++) {  // Access elements consecutively from diagonal forward
        tmp = bptr[j];
        bptr[j] = alpha * aptr[j + i];
        aptr[j + i] = alpha * tmp;
    }
    aptr += lda;
}
}
