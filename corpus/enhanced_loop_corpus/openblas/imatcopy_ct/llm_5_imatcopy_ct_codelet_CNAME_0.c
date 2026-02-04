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
    bptr = &a[i];
    bptr[i * lda] = alpha * bptr[i * lda];
    if (i >= rows) continue;
    for (j = i + 1; j < rows && j < lda; j++) {
        if (j * lda < rows) {
            tmp = bptr[j * lda];
            bptr[j * lda] = alpha * aptr[j];
            aptr[j] = alpha * tmp;
        }
    }
    aptr += lda;
}
}
