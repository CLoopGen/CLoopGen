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
    j = 0;
    if (rows > 0) {
        do {
            aptr[j * lda] = 0.;
            j++;
        } while (j < rows);
    }
}
}
