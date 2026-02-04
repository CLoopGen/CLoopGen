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
        aptr[j + i * lda] = 0.; // Eliminate WAW across iterations by writing to unique offset, removing loop-carried dependence on aptr update
    }
}
// Removed aptr += lda inside loop; now base pointer aptr is unchanged, and indexing is explicit
}
