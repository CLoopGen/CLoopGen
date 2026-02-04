#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG rows;
extern BLASLONG cols;
extern float alpha_r;
extern float alpha_i;
extern BLASLONG lda;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG ia;
extern float *aptr;
extern float a0;
extern float a1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < cols; i++) {
    for (j = 0; j < rows; j++) {
        BLASLONG idx = j * 2;
        a0 = aptr[idx];
        a1 = aptr[idx + 1];
        aptr[idx] = alpha_r * a0 - alpha_i * a1;
        aptr[idx + 1] = alpha_i * a0 + alpha_r * a1;
    }
    aptr += lda;
}
}
