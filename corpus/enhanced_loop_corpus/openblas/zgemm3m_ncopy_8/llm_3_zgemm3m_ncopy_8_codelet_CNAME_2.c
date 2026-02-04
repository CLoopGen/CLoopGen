#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG i;
extern float *a_offset1;
extern float *a_offset2;
extern float *b_offset;
extern float a1;
extern float a2;
extern float a3;
extern float a4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
long stride = 4;
for (i = 0; i < m; i++) {
    long idx_a1 = i * stride;
    long idx_a2 = i * stride;
    long idx_b = i * stride;
    a1 = *(a_offset1 + idx_a1 / 2);
    a2 = *(a_offset1 + idx_a1 / 2 + 1);
    a3 = *(a_offset2 + idx_a2 / 2);
    a4 = *(a_offset2 + idx_a2 / 2 + 1);
    *(b_offset + idx_b)     = a1 + a3;
    *(b_offset + idx_b + 1) = a2 + a4;
}
}
