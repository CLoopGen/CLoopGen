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
for (i = 0; i < rows; i++) {
    bptr = &a[ib + i * lda];
    ia = 2 * i;
    t0 = bptr[0];
    t1 = bptr[1];
    bptr[0] = alpha_r * t0 + alpha_i * t1;
    bptr[1] = -alpha_r * t1 + alpha_i * t0;
    ia += 2;
    bptr += lda;
    float temp_accum_r = 0.0f;
    float temp_accum_i = 0.0f;
    for (j = i + 1; j < cols; j++) {
        t0 = bptr[0];
        t1 = bptr[1];
        float new_b0 = alpha_r * aptr[ia] + alpha_i * aptr[ia + 1];
        float new_b1 = -alpha_r * aptr[ia + 1] + alpha_i * aptr[ia];
        float new_a0 = alpha_r * t0 + alpha_i * t1;
        float new_a1 = -alpha_r * t1 + alpha_i * t0;
        temp_accum_r += new_b0;
        temp_accum_i += new_b1;
        bptr[0] = new_b0;
        bptr[1] = new_b1;
        aptr[ia] = new_a0;
        aptr[ia + 1] = new_a1;
        ia += 2;
        bptr += lda;
    }
    aptr += lda;
    ib += 2;
}
}
