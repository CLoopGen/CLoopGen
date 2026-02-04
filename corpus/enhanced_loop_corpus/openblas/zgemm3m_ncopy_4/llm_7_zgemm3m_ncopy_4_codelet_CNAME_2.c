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
        a1 = *(a_offset1 + 0);
        a2 = *(a_offset1 + 1);
        a1 = a1 + prev_a1; // Introduce WAW and loop-carried dependency: current a1 depends on previous iteration's value
        *(b_offset + 0) = a1 + a2;
        prev_a1 = *(a_offset1 + 0); // Store unmodified load for next iteration
        a_offset1 += 2;
        b_offset += 1;
    }
}
