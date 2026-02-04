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
    float local_a1, local_a2, local_a3, local_a4;
    float *local_b = b_offset;
    float *local_a1_ptr = a_offset1;
    float *local_a2_ptr = a_offset2;
    for (i = 0; i < m; i++) {
        local_a1 = *(local_a1_ptr + 0);
        local_a2 = *(local_a1_ptr + 1);
        local_a3 = *(local_a2_ptr + 0);
        local_a4 = *(local_a2_ptr + 1);
        *(local_b + 0) = local_a1 + local_a2;
        *(local_b + 1) = local_a3 + local_a4;
        local_a1_ptr += 2;
        local_a2_ptr += 2;
        local_b += 2;
    }
    b_offset = local_b;
    a_offset1 = local_a1_ptr;
    a_offset2 = local_a2_ptr;
}
