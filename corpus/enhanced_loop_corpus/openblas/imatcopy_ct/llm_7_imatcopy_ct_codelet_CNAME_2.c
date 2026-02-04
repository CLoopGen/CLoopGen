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
    bptr = &a[i];
    for (j = i; j < rows; j++) {
        float tmp1 = bptr[j * lda];
        float tmp2 = aptr[j];
        bptr[j * lda] = tmp2;
        aptr[j] = tmp1;
    }
    aptr += lda;
}
}
