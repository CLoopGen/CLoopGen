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
    if (i % 2 == 0) {
        bptr[i * lda] = alpha * bptr[i * lda];
        for (j = i + 1; j < cols; j++) {
            tmp = bptr[j * lda];
            bptr[j * lda] = alpha * aptr[j];
            aptr[j] = alpha * tmp;
        }
    } else {
        bptr[i * lda] = 0.0f;
        for (j = i + 1; j < cols; j++) {
            aptr[j] = 0.0f;
        }
    }
    aptr += lda;
}
}
