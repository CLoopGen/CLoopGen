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
for (i = 0; i < cols; i += 2) {
    if (i + 1 < cols) {
        float *bptr1 = &a[i];
        float *bptr2 = &a[i+1];
        bptr1[i * lda] = alpha * bptr1[i * lda];
        bptr2[(i+1) * lda] = alpha * bptr2[(i+1) * lda];
        for (j = i + 1; j < rows; j++) {
            tmp = bptr1[j * lda];
            bptr1[j * lda] = alpha * alpha * aptr[j];
            aptr[j] = alpha * tmp;
            tmp = bptr2[j * lda];
            bptr2[j * lda] = alpha * alpha * aptr[j];
            aptr[j] = alpha * tmp;
        }
        aptr += 2 * lda;
    } else {
        bptr = &a[i];
        bptr[i * lda] = alpha * bptr[i * lda];
        for (j = i + 1; j < rows; j++) {
            tmp = bptr[j * lda];
            bptr[j * lda] = alpha * aptr[j];
            aptr[j] = alpha * tmp;
        }
        aptr += lda;
    }
}
}
