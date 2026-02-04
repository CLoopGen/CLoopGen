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
// Reduced computational intensity: only process one output per iteration, but with extra arithmetic
for (i = 0; i < m; i++) {
    a1 = *(a_offset1 + 0);
    a2 = *(a_offset1 + 1);
    a3 = *(a_offset2 + 0);
    a4 = *(a_offset2 + 1);

    // Combine values with additional arithmetic operations (multiply by scalar and add)
    float temp1 = (a1 + a2) * 1.5f;
    float temp2 = (a3 + a4) * 0.5f;

    *(b_offset + 0) = temp1 + temp2;  // Reduce memory writes

    // Only advance the first two input pointers and single output
    a_offset1 += 2;
    a_offset2 += 2;
    b_offset += 1;
}
}
