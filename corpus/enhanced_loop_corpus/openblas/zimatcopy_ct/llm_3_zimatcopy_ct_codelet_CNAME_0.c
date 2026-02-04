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
    BLASLONG base_idx = ib + i * lda;
    ia = 2 * i;
    float *a_base = &a[base_idx];
    t0 = a_base[0];
    t1 = a_base[1];
    a_base[0] = alpha_r * t0 - alpha_i * t1;
    a_base[1] = alpha_r * t1 + alpha_i * t0;
    ia += 2;
    for (j = i + 1; j < rows; j++) {
        BLASLONG offset = j * lda;
        t0 = a[offset + 0];
        t1 = a[offset + 1];
        a[offset + 0] = alpha_r * aptr[ia] - alpha_i * aptr[ia + 1];
        a[offset + 1] = alpha_r * aptr[ia + 1] + alpha_i * aptr[ia];
        aptr[ia] = alpha_r * t0 - alpha_i * t1;
        aptr[ia + 1] = alpha_r * t1 + alpha_i * t0;
        ia += 2;
    }
    aptr += lda;
    ib += 2;
}
}
