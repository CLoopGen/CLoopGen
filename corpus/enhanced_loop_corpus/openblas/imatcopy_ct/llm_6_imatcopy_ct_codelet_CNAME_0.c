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
    tmp = alpha * bptr[i * lda];
    bptr[i * lda] = tmp;
    for (j = i + 1; j < rows; j++) {
        BLASLONG index = j * lda;
        float temp_current = bptr[index];
        float scaled_aptr = alpha * aptr[j];
        bptr[index] = scaled_aptr;
        aptr[j] = alpha * temp_current;
    }
    aptr += lda;
}
}
