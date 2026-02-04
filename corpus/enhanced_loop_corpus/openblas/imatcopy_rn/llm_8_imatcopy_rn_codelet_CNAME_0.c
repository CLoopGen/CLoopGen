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
for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j += 2) {
        if (j + 1 < cols) {
            aptr[j]     = alpha * aptr[j];
            aptr[j + 1] = alpha * aptr[j + 1];
        } else {
            aptr[j] = alpha * aptr[j];
        }
    }
    aptr += lda;
}
}
