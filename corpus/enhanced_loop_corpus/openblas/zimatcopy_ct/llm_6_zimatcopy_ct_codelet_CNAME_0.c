#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG rows;
extern BLASLONG cols;
extern float alpha_r;
extern float alpha_i;
extern float *a;
extern BLASLONG lda;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG ia;
extern BLASLONG ib;
extern float *aptr;
extern float *bptr;
extern float t0;
extern float t1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < cols; i++) {
    bptr = &a[ib + i * lda];
    ia = 2 * i;
    t0 = bptr[0];
    t1 = bptr[1];
    float temp_r = alpha_r * t0 - alpha_i * t1;
    float temp_i = alpha_r * t1 + alpha_i * t0;
    bptr[0] = temp_r;
    bptr[1] = temp_i;
    bptr += lda;
    ia += 2;
    for (j = i + 1; j < rows; j++) {
        float a_val_r = aptr[ia];
        float a_val_i = aptr[ia + 1];
        float b_val_r = bptr[0];
        float b_val_i = bptr[1];
        bptr[0] = alpha_r * a_val_r - alpha_i * a_val_i;
        bptr[1] = alpha_r * a_val_i + alpha_i * a_val_r;
        aptr[ia] = alpha_r * b_val_r - alpha_i * b_val_i;
        aptr[ia + 1] = alpha_r * b_val_i + alpha_i * b_val_r;
        ia += 2;
        bptr += lda;
    }
    aptr += lda;
    ib += 2;
}
}
