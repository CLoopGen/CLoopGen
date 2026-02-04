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
    for (j = i; j < cols; j++) {
        if (j == i) {
            bptr[j * lda] = alpha * bptr[j * lda];
        } else {
            float temp_b = bptr[j * lda];
            bptr[j * lda] = alpha * aptr[j];
            aptr[j] = alpha * temp_b;
        }
    }
    aptr += lda;
}
}
