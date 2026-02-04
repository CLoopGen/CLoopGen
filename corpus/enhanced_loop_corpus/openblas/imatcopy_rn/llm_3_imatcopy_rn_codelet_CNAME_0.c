#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG rows;
extern BLASLONG cols;
extern float alpha;
extern BLASLONG lda;
extern BLASLONG i;
extern BLASLONG j;
extern float *aptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < cols; j++) {
    for (i = 0; i < rows; i++) {
        aptr[i * lda + j] = alpha * aptr[i * lda + j];
    }
}
}
