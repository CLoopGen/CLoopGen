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
    for (j = i + 1; j < cols; j++) {
        if (ia % 4 == 0) {
            t0 = bptr[0];
            t1 = bptr[1];
            bptr[0] = alpha_r * aptr[ia] + alpha_i * aptr[ia + 1];
            bptr[1] = -alpha_r * aptr[ia + 1] + alpha_i * aptr[ia];
            aptr[ia] = alpha_r * t0 + alpha_i * t1;
            aptr[ia + 1] = -alpha_r * t1 + alpha_i * t0;
        } else {
            aptr[ia] = alpha_r * aptr[ia] - alpha_i * aptr[ia + 1];
            aptr[ia + 1] = alpha_r * aptr[ia + 1] + alpha_i * aptr[ia];
        }
        ia += 2;
        bptr += lda;
    }
    aptr += lda;
    ib += 2;
}
}
