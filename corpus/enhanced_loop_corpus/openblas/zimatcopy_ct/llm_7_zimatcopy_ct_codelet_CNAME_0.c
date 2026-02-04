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
    bptr[0] = alpha_r * t0 - alpha_i * t1;
    bptr[1] = alpha_r * t1 + alpha_i * t0;
    bptr += lda;
    ia += 2;
    BLASLONG local_offset = ia;
    float *local_aptr = aptr;
    for (j = i + 1; j < rows; j++) {
        t0 = bptr[0];
        t1 = bptr[1];
        float ar = local_aptr[local_offset];
        float ai = local_aptr[local_offset + 1];
        bptr[0] = alpha_r * ar - alpha_i * ai;
        bptr[1] = alpha_r * ai + alpha_i * ar;
        local_aptr[local_offset] = alpha_r * t0 - alpha_i * t1;
        local_aptr[local_offset + 1] = alpha_r * t1 + alpha_i * t0;
        local_offset += 2;
        bptr += lda;
    }
    aptr += lda;
    ib += 2;
}
}
