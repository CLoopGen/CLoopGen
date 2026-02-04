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
    float temp_sum;
    for (i = 0; i < m; i++) {
        a1 = *(a_offset1 + 0);
        a2 = *(a_offset1 + 1);
        temp_sum = a1 + a2;
        *(b_offset + 0) = temp_sum;
        a_offset1 += 2;
        b_offset += 1;
    }
}
