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
    BLASLONG offset = i * lda;
    float *base_a = &a[offset];
    float *base_aptr = &aptr[offset];
    // Sequentially process elements in a strided array as consecutive blocks
    base_a[0] = alpha * base_a[0];
    for (j = 1; j < rows; j++) {
        tmp = base_a[j];
        base_a[j] = alpha * base_aptr[j];
        base_aptr[j] = alpha * tmp;
    }
}
}
