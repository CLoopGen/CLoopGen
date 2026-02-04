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
    BLASLONG base_a = i * 8;  
    BLASLONG base_b = i * 4;

    float *src1 = (float*)((char*)a_offset1 + base_a);
    float *src2 = (float*)((char*)a_offset2 + base_a);
    float *src3 = (float*)((char*)a_offset3 + base_a);
    float *src4 = (float*)((char*)a_offset4 + base_a);
    float *dst = b_offset + base_b;

    a1 = src1[0]; a2 = src1[1];
    a3 = src2[0]; a4 = src2[1];
    a5 = src3[0]; a6 = src3[1];
    a7 = src4[0]; a8 = src4[1];

    dst[0] = a1 + a2;
    dst[1] = a3 + a4;
    dst[2] = a5 + a6;
    dst[3] = a7 + a8;
}
}
