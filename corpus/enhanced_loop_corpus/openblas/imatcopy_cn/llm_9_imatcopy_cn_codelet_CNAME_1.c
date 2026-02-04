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
for (i = 0; i < cols; i += 2) {
    if (i + 1 < cols) {
        for (j = 0; j < rows; j++) {
            aptr[j] = 0.;
            aptr[j + lda] = 0.;
        }
        aptr += 2 * lda;
    } else {
        for (j = 0; j < rows; j++) {
            aptr[j] = 0.;
        }
        aptr += lda;
    }
}
}
