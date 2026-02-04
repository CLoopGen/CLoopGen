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
for (i = 0; i < cols; i++) {
    bptr = &a[i * lda];  // Changed access to column-major base pointer
    bptr[0] = alpha * bptr[0];
    for (j = 1; j < rows - i; j++) {  // Adjusted bounds and stride pattern
        tmp = bptr[j];
        bptr[j] = alpha * aptr[(i + j) * lda];
        aptr[(i + j) * lda] = alpha * tmp;
    }
    aptr += lda;
}
}
