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
BLASLONG total_elements = rows * 2;
for (i = 0; i < cols; i++) {
    BLASLONG offset = 0;
    for (j = 0; j < total_elements; j += 2) {
        a0 = aptr[offset + j];
        a1 = aptr[offset + j + 1];
        aptr[offset + j] = alpha_r * a0 + alpha_i * a1;
        aptr[offset + j + 1] = -alpha_i * a0 + alpha_r * a1;
    }
    aptr += lda;
}
}
