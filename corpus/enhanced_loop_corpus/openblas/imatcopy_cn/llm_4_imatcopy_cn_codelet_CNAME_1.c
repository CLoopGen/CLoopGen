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
    if (lda > rows) {
        for (j = 0; j < rows; j++) {
            aptr[j] = 0.;
        }
    } else {
        for (j = 0; j < rows; j += 2) {
            aptr[j] = 0.;
            if (j + 1 < rows) aptr[j + 1] = 0.;
        }
    }
    aptr += lda;
}
}
