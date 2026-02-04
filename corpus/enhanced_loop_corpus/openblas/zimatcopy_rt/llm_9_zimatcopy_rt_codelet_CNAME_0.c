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
for (i = 0; i < rows; i += 2) {
    if (i + 1 >= rows) break;
    bptr = &a[ib + i * lda];
    ia = 2 * i;
    t0 = bptr[0];
    t1 = bptr[1];
    bptr[0] = alpha_r * t0 - alpha_i * t1;
    bptr[1] = alpha_r * t1 + alpha_i * t0;
    bptr += lda;
    ia += 2;

    float *bptr2 = &a[ib + (i+1) * lda];
    int ia2 = 2 * (i+1);
    float t2 = bptr2[0];
    float t3 = bptr2[1];
    bptr2[0] = alpha_r * t2 - alpha_i * t3;
    bptr2[1] = alpha_r * t3 + alpha_i * t2;
    bptr2 += lda;
    ia2 += 2;

    for (j = i + 1; j < cols; j++) {
        t0 = bptr[0];
        t1 = bptr[1];
        float a0 = aptr[ia], a1 = aptr[ia + 1];
        bptr[0] = alpha_r * a0 - alpha_i * a1;
        bptr[1] = alpha_r * a1 + alpha_i * a0;
        aptr[ia] = alpha_r * t0 - alpha_i * t1;
        aptr[ia + 1] = alpha_r * t1 + alpha_i * t0;

        t2 = bptr2[0];
        t3 = bptr2[1];
        float a2 = aptr[ia2], a3 = aptr[ia2 + 1];
        bptr2[0] = alpha_r * a2 - alpha_i * a3;
        bptr2[1] = alpha_r * a3 + alpha_i * a2;
        aptr[ia2] = alpha_r * t2 - alpha_i * t3;
        aptr[ia2 + 1] = alpha_r * t3 + alpha_i * t2;

        ia += 2; ia2 += 2;
        bptr += lda; bptr2 += lda;
    }
    aptr += 2 * lda;
    ib += 4;
}
}
