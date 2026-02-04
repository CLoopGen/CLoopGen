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
for (i = 0; i < rows * cols; i++) {
    aptr[i % cols] = 0.;
    if ((i + 1) % cols == 0) {
        aptr += lda;
    }
}
}
