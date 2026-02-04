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
for (i = 0; i < cols && rows > 0; i++) {
    bptr = &a[ib + i * lda];
    ia = 2 * i;
    t0 = bptr[0];
    t1 = bptr[1];
    bptr[0] = alpha_r * t0;
    bptr[1] = alpha_i * t1;
    ia += 2;
    bptr += lda;
    if (i % 2 == 0) {
        for (j = i + 1; j < rows; j += 2) {
            if (j + 1 >= rows) break;
            t0 = bptr[0]; t1 = bptr[1];
            float t0_next = bptr[lda], t1_next = bptr[lda + 1];
            bptr[0] = alpha_r * aptr[ia] + alpha_i * aptr[ia + 1];
            bptr[1] = -alpha_r * aptr[ia + 1] + alpha_i * aptr[ia];
            bptr[lda] = alpha_r * aptr[ia + 2] + alpha_i * aptr[ia + 3];
            bptr[lda + 1] = -alpha_r * aptr[ia + 3] + alpha_i * aptr[ia + 2];
            aptr[ia] = alpha_r * t0 + alpha_i * t1;
            aptr[ia + 1] = -alpha_r * t1 + alpha_i * t0;
            aptr[ia + 2] = alpha_r * t0_next + alpha_i * t1_next;
            aptr[ia + 3] = -alpha_r * t1_next + alpha_i * t0_next;
            ia += 4;
            bptr += 2 * lda;
        }
    } else {
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
    }
    aptr += lda;
    ib += 2;
}
}
