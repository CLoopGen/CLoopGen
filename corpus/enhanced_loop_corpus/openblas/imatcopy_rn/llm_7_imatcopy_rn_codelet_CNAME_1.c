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
    for (j = 1; j < cols; j++) {
        aptr[j] = aptr[j-1]; // Introduce RAW dependency: each element depends on the previous
    }
    if (cols > 0) aptr[0] = 0.; // Initialize first element after potential use
    aptr += lda;
}
}
