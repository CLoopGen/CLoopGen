#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG i;
extern float *a_offset1;
extern float *b_offset;
extern float a1;
extern float a2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev_a1 = 0.0f;
    for (i = 0; i < m; i++) {
        a1 = *(a_offset1 + 0) + prev_a1; // Introduce loop-carried dependency: WAW/RAR via prev_a1
        a2 = *(a_offset1 + 1);
        *(b_offset + 0) = a1 + a2;
        prev_a1 = *(a_offset1 + 0); // Store original value for next iteration
        a_offset1 += 2;
        b_offset += 1;
    }
}
