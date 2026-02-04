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
for (i = 0; i < rows; i += 2) {
    if (i + 1 < rows) {
        for (j = 0; j < cols; j++) {
            aptr[j] = 0.;
        }
        aptr += lda;
        for (j = 0; j < cols; j++) {
            aptr[j] = 0.;
        }
        aptr += lda;
    } else {
        for (j = 0; j < cols; j++) {
            aptr[j] = 0.;
        }
        aptr += lda;
    }
}
}
