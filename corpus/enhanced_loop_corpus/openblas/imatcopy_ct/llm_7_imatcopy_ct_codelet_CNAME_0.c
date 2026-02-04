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
    BLASLONG diag_index = i * lda;
    bptr[diag_index] = alpha * bptr[diag_index];
    for (j = i + 1; j < rows; j++) {
        BLASLONG idx = j * lda;
        float original_b = bptr[idx];
        bptr[idx] = alpha * aptr[j];
        aptr[j] = alpha * original_b;
    }
    aptr += lda;
}
}
