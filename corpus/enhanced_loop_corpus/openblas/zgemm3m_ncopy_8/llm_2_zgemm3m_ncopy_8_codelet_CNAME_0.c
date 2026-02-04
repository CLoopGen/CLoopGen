#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG i;
extern float *a_offset1;
extern float *a_offset2;
extern float *a_offset3;
extern float *a_offset4;
extern float *a_offset5;
extern float *a_offset6;
extern float *a_offset7;
extern float *a_offset8;
extern float *b_offset;
extern float a1;
extern float a2;
extern float a3;
extern float a4;
extern float a5;
extern float a6;
extern float a7;
extern float a8;
extern float a9;
extern float a10;
extern float a11;
extern float a12;
extern float a13;
extern float a14;
extern float a15;
extern float a16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    BLASLONG idx_a = i * 2;
    BLASLONG idx_b = i * 8;
    a1 = a_offset1[idx_a];
    a2 = a_offset1[idx_a + 1];
    a3 = a_offset2[idx_a];
    a4 = a_offset2[idx_a + 1];
    a5 = a_offset3[idx_a];
    a6 = a_offset3[idx_a + 1];
    a7 = a_offset4[idx_a];
    a8 = a_offset4[idx_a + 1];
    a9 = a_offset5[idx_a];
    a10 = a_offset5[idx_a + 1];
    a11 = a_offset6[idx_a];
    a12 = a_offset6[idx_a + 1];
    a13 = a_offset7[idx_a];
    a14 = a_offset7[idx_a + 1];
    a15 = a_offset8[idx_a];
    a16 = a_offset8[idx_a + 1];
    b_offset[idx_b]     = a1 + a2;
    b_offset[idx_b + 1] = a3 + a4;
    b_offset[idx_b + 2] = a5 + a6;
    b_offset[idx_b + 3] = a7 + a8;
    b_offset[idx_b + 4] = a9 + a10;
    b_offset[idx_b + 5] = a11 + a12;
    b_offset[idx_b + 6] = a13 + a14;
    b_offset[idx_b + 7] = a15 + a16;
}
}
