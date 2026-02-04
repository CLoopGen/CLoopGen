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
    BLASLONG base_idx[8];
    base_idx[0] = (i << 1);          // 2*i
    base_idx[1] = base_idx[0] + 2;
    base_idx[2] = base_idx[0] + 4;
    base_idx[3] = base_idx[0] + 6;
    base_idx[4] = base_idx[0] + 8;
    base_idx[5] = base_idx[0] + 10;
    base_idx[6] = base_idx[0] + 12;
    base_idx[7] = base_idx[0] + 14;

    float *ptrs_a[8] = {
        a_offset1, a_offset2, a_offset3, a_offset4,
        a_offset5, a_offset6, a_offset7, a_offset8
    };

    a1 = ptrs_a[0][base_idx[0]];     a2 = ptrs_a[0][base_idx[0] + 1];
    a3 = ptrs_a[1][base_idx[1]];     a4 = ptrs_a[1][base_idx[1] + 1];
    a5 = ptrs_a[2][base_idx[2]];     a6 = ptrs_a[2][base_idx[2] + 1];
    a7 = ptrs_a[3][base_idx[3]];     a8 = ptrs_a[3][base_idx[3] + 1];
    a9 = ptrs_a[4][base_idx[4]];     a10 = ptrs_a[4][base_idx[4] + 1];
    a11 = ptrs_a[5][base_idx[5]];    a12 = ptrs_a[5][base_idx[5] + 1];
    a13 = ptrs_a[6][base_idx[6]];    a14 = ptrs_a[6][base_idx[6] + 1];
    a15 = ptrs_a[7][base_idx[7]];    a16 = ptrs_a[7][base_idx[7] + 1];

    for (BLASLONG j = 0; j < 8; j++) {
        b_offset[i * 8 + j] = *((float *)&a1 + j * 2) + *((float *)&a2 + j * 2);
    }
}
}
