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
    BLASLONG offset_i = i * lda;
    bptr = &a[offset_i];
    aptr = &a[offset_i];  // Use separate strided access via precomputed offsets
    bptr[0] = alpha * bptr[0];
    for (j = i + 1; j < cols; j++) {
        BLASLONG offset_j = j * lda;  // Strided access using explicit offset calculation
        tmp = bptr[offset_j / lda];
        bptr[offset_j / lda] = alpha * aptr[j];
        aptr[j] = alpha * tmp;
    }
    aptr += lda;
}
}
