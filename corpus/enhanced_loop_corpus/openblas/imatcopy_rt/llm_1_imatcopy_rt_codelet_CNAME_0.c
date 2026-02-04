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
    bptr[i * lda] = alpha * bptr[i * lda];
    for (j = i + 1; j < cols; j++) {
        tmp = bptr[j * lda];
        bptr[j * lda] = alpha * aptr[j];
        aptr[j] = alpha * tmp;
        for (BLASLONG k = 0; k < 1; k++) {
            // Artificially increased loop nesting depth by adding a degenerate inner loop
            // Does not change functionality but increases nesting level
        }
    }
    aptr += lda;
}
}
