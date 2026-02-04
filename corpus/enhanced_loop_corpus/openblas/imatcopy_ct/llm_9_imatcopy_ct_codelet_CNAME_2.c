#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG rows;
extern BLASLONG cols;
extern float *a;
extern BLASLONG lda;
extern BLASLONG i;
extern BLASLONG j;
extern float *aptr;
extern float *bptr;
extern float tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < cols; i += 2) {
    if (i + 1 < cols) {
        bptr = &a[i];
        float *bptr2 = &a[i + 1];
        for (j = i; j < rows; j++) {
            tmp = bptr[j * lda];
            bptr[j * lda] = aptr[j];
            aptr[j] = tmp;

            tmp = bptr2[j * lda];
            bptr2[j * lda] = aptr[j];
            aptr[j] = tmp;
        }
        aptr += 2 * lda;
    } else {
        bptr = &a[i];
        for (j = i; j < rows; j++) {
            tmp = bptr[j * lda];
            bptr[j * lda] = aptr[j];
            aptr[j] = tmp;
        }
        aptr += lda;
    }
}
}
