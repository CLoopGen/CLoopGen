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
    ia = 0;
    float local_alpha_r = alpha_r;
    float local_alpha_i = alpha_i;
    float prev_a0 = 0.0f, prev_a1 = 0.0f;
    int first = 1;
    for (j = 0; j < rows; j++) {
        a0 = aptr[ia];
        a1 = aptr[ia + 1];
        if (!first) {
            a0 += prev_a0;
            a1 += prev_a1;
        }
        float result_a0 = local_alpha_r * a0 + local_alpha_i * a1;
        float result_a1 = -local_alpha_r * a1 + local_alpha_i * a0;
        aptr[ia] = result_a0;
        aptr[ia + 1] = result_a1;
        prev_a0 = result_a0;
        prev_a1 = result_a1;
        first = 0;
        ia += 2;
    }
    aptr += lda;
}
}
