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
for (i = 0; i < cols; i++) {
    bptr = &a[i];
    float temp_store = 0.0f;
    for (j = i; j < rows; j++) {
        temp_store = bptr[j * lda];
        bptr[j * lda] = aptr[j];
        aptr[j] = temp_store;
    }
    aptr += lda;
}
}
