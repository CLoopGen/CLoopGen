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
    for (j = 0; j < rows; j++) {
        aptr[j] = (j % 2 == 0) ? 0. : 1.;
    }
    aptr += lda;
}
}
