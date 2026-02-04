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
    BLASLONG base = i * lda;
    for (j = 0; j < rows; j += 4) {
        if (j + 0 < rows) aptr[base + j + 0] = 0.;
        if (j + 1 < rows) aptr[base + j + 1] = 0.;
        if (j + 2 < rows) aptr[base + j + 2] = 0.;
        if (j + 3 < rows) aptr[base + j + 3] = 0.;
    }
}
}
