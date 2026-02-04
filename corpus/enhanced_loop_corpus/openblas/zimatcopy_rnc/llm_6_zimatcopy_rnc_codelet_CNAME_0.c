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
for (i = 0; i < rows; i++) {
    ia = 0;
    float temp_alpha_r = alpha_r;
    float temp_alpha_i = alpha_i;
    for (j = 0; j < cols; j++) {
        a0 = aptr[ia];
        a1 = aptr[ia + 1];
        float new_a0 = temp_alpha_r * a0 + temp_alpha_i * a1;
        float new_a1 = -temp_alpha_r * a1 + temp_alpha_i * a0;
        aptr[ia] = new_a0;
        aptr[ia + 1] = new_a1;
        ia += 2;
    }
    aptr += lda;
}
}
