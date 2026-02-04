#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG rows;
extern BLASLONG cols;
extern float *a;
extern BLASLONG lda;
extern BLASLONG i;
extern BLASLONG j;
extern float *aptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < rows; j++) {
    for (i = 0; i < cols; i++) {
        a[i + j * lda] = 0.;
    }
}
}
