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
    BLASLONG offset_b = ib + i * lda;
    BLASLONG offset_a = i * lda;
    ia = 2 * i;
    t0 = a[offset_b];
    t1 = a[offset_b + 1];
    a[offset_b] = alpha_r * t0 + alpha_i * t1;
    a[offset_b + 1] = -alpha_r * t1 + alpha_i * t0;
    ia += 2;
    for (j = i + 1; j < rows; j++) {
        offset_b += lda;
        offset_a += lda;
        t0 = a[offset_b];
        t1 = a[offset_b + 1];
        a[offset_b] = alpha_r * a[offset_a + ia] + alpha_i * a[offset_a + ia + 1];
        a[offset_b + 1] = -alpha_r * a[offset_a + ia + 1] + alpha_i * a[offset_a + ia];
        a[offset_a + ia] = alpha_r * t0 + alpha_i * t1;
        a[offset_a + ia + 1] = -alpha_r * t1 + alpha_i * t0;
        ia += 2;
    }
    ib += 2;
}
}
