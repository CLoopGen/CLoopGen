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
for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
        if (j % 2 == 0) {
            aptr[j] = 0.;
        } else {
            aptr[j] = 0.;
        }
    }
    aptr += lda;
}
}
