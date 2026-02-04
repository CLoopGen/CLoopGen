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
for (i = 0; i < cols && i < rows; i++) {
    bptr = &a[i * lda]; 
    tmp = bptr[i];
    bptr[i] = alpha * tmp;
    for (j = i + 1; j < rows; j += 2) {
        float temp1 = bptr[j];
        float temp2 = (j + 1 < rows) ? bptr[j + 1] : 0.0f;
        bptr[j] = alpha * aptr[j];
        aptr[j] = alpha * temp1;
        if (j + 1 < rows) {
            bptr[j + 1] = alpha * aptr[j + 1];
            aptr[j + 1] = alpha * temp2;
        }
    }
    aptr += lda;
}
}
