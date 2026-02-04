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
    float *base_ptr = aptr + i * lda;
    for (j = 0, ia = 0; j < rows; j++, ia += 2) {
        a0 = base_ptr[ia];
        a1 = base_ptr[ia + 1];
        base_ptr[ia]     = alpha_r * a0 - alpha_i * a1;
        base_ptr[ia + 1] = alpha_r * a1 + alpha_i * a0;
    }
}
}
