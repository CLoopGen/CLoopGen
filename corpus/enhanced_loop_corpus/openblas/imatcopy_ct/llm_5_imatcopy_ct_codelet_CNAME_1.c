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
for (i = 0; i < cols; i++) {
    aptr = &a[i];
    for (j = 0; j < rows; j++) {
        if (j % 2 == 0) {
            aptr[j * lda] = 0.;
        } else {
            aptr[j * lda] = 0.;
        }
    }
}
}
