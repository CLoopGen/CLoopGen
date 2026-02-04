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
    float *b_curr = &a[ib + i * lda];
    float *a_curr = &aptr[2 * i];
    ia = 0;
    t0 = b_curr[0];
    t1 = b_curr[1];
    b_curr[0] = alpha_r * t0 - alpha_i * t1;
    b_curr[1] = alpha_r * t1 + alpha_i * t0;
    b_curr += lda;
    for (j = i + 1; j < cols; j++) {
        t0 = b_curr[0];
        t1 = b_curr[1];
        b_curr[0] = alpha_r * a_curr[ia] - alpha_i * a_curr[ia + 1];
        b_curr[1] = alpha_r * a_curr[ia + 1] + alpha_i * a_curr[ia];
        a_curr[ia] = alpha_r * t0 - alpha_i * t1;
        a_curr[ia + 1] = alpha_r * t1 + alpha_i * t0;
        ia += 2;
        b_curr += lda;
    }
    aptr += lda;
    ib += 2;
}
}
