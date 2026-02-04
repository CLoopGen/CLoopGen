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
    for (j = i + 1; j < cols; j += 2) {
        if (j + 1 < cols) {
            float tmp1 = bptr[j * lda];
            float tmp2 = bptr[(j + 1) * lda];
            bptr[j * lda] = alpha * aptr[j];
            bptr[(j + 1) * lda] = alpha * aptr[j + 1];
            aptr[j] = alpha * tmp1;
            aptr[j + 1] = alpha * tmp2;
        } else {
            tmp = bptr[j * lda];
            bptr[j * lda] = alpha * aptr[j];
            aptr[j] = alpha * tmp;
        }
    }
    aptr += lda;
}
}
