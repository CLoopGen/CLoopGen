#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG rows;
extern BLASLONG cols;
extern BLASLONG lda;
extern BLASLONG i;
extern BLASLONG j;
extern float *aptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < cols; i++) {
    j = 0;
    for (; j < rows; j++) {
        aptr[j] = 0.;
        if (j == rows / 2) {
            j++; // Skip the next element after midpoint
            continue;
        }
    }
    aptr += lda;
}
}
