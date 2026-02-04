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
    bptr = &a[i];
    tmp = bptr[i * lda];
    bptr[i * lda] = alpha * tmp;
    for (j = i + 1; j < cols; j++) {
        tmp = bptr[j * lda];
        bptr[j * lda] = alpha * tmp;
    }
    aptr += lda;
}
}
