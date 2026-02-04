#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;
extern float *ao5;
extern float *ao6;
extern float *ao7;
extern float *ao8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii++) {
    float *base_b = b + ii * 16;
    float *ptrs[8] = {ao1, ao2, ao3, ao4, ao5, ao6, ao7, ao8};
    BLASLONG offset = ii * 2;
    
    base_b[0]  = ptrs[0][offset + 0];
    base_b[1]  = ptrs[0][offset + 1];
    base_b[2]  = ptrs[1][offset + 0];
    base_b[3]  = ptrs[1][offset + 1];
    base_b[4]  = ptrs[2][offset + 0];
    base_b[5]  = ptrs[2][offset + 1];
    base_b[6]  = ptrs[3][offset + 0];
    base_b[7]  = ptrs[3][offset + 1];
    base_b[8]  = ptrs[4][offset + 0];
    base_b[9]  = ptrs[4][offset + 1];
    base_b[10] = ptrs[5][offset + 0];
    base_b[11] = ptrs[5][offset + 1];
    base_b[12] = ptrs[6][offset + 0];
    base_b[13] = ptrs[6][offset + 1];
    base_b[14] = ptrs[7][offset + 0];
    base_b[15] = ptrs[7][offset + 1];
}
}
