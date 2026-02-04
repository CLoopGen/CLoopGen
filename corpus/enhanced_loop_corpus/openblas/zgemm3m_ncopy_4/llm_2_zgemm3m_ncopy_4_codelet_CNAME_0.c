#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG i;
extern float *a_offset1;
extern float *a_offset2;
extern float *a_offset3;
extern float *a_offset4;
extern float *b_offset;
extern float a1;
extern float a2;
extern float a3;
extern float a4;
extern float a5;
extern float a6;
extern float a7;
extern float a8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    BLASLONG idx_a1 = i * 2;
    BLASLONG idx_a2 = i * 2;
    BLASLONG idx_a3 = i * 2;
    BLASLONG idx_a4 = i * 2;
    BLASLONG idx_b = i * 4;

    a1 = *(a_offset1 + idx_a1 + 0);
    a2 = *(a_offset1 + idx_a1 + 1);
    a3 = *(a_offset2 + idx_a2 + 0);
    a4 = *(a_offset2 + idx_a2 + 1);
    a5 = *(a_offset3 + idx_a3 + 0);
    a6 = *(a_offset3 + idx_a3 + 1);
    a7 = *(a_offset4 + idx_a4 + 0);
    a8 = *(a_offset4 + idx_a4 + 1);

    *(b_offset + idx_b + 0) = a1 + a2;
    *(b_offset + idx_b + 1) = a3 + a4;
    *(b_offset + idx_b + 2) = a5 + a6;
    *(b_offset + idx_b + 3) = a7 + a8;
}
}
