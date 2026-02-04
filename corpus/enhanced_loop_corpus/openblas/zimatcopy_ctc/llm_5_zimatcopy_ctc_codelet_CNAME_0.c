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
    bptr[0] = alpha_r * t0 + alpha_i * t1;
    bptr[1] = -alpha_r * t1 + alpha_i * t0;
    ia += 2;
    bptr += lda;
    if (i % 2 == 0) {
        for (j = i + 1; j < rows; j++) {
            t0 = bptr[0];
            t1 = bptr[1];
            bptr[0] = alpha_r * aptr[ia] + alpha_i * aptr[ia + 1];
            bptr[1] = -alpha_r * aptr[ia + 1] + alpha_i * aptr[ia];
            aptr[ia] = alpha_r * t0 + alpha_i * t1;
            aptr[ia + 1] = -alpha_r * t1 + alpha_i * t0;
            ia += 2;
            bptr += lda;
        }
    } else {
        for (j = i + 1; j < rows; j++) {
            float temp_r = aptr[ia];
            float temp_i = aptr[ia + 1];
            aptr[ia] = alpha_r * bptr[0] + alpha_i * bptr[1];
            aptr[ia + 1] = -alpha_r * bptr[1] + alpha_i * bptr[0];
            bptr[0] = alpha_r * temp_r + alpha_i * temp_i;
            bptr[1] = -alpha_r * temp_i + alpha_i * temp_r;
            ia += 2;
            bptr += lda;
        }
    }
    aptr += lda;
    ib += 2;
}
}
