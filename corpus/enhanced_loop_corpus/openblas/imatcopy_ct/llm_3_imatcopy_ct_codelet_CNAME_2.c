#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG rows;
extern BLASLONG cols;
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
    BLASLONG offset = i;
    bptr = &a[offset];
    for (j = i; j < rows; j++) {
        BLASLONG linear_idx = j * lda;
        tmp = bptr[linear_idx];
        bptr[linear_idx] = aptr[j * 1];
        aptr[j * 1] = tmp;
    }
    aptr += lda;
}
}
