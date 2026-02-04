#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern float *a_offset;
extern float a1;
extern float a2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG stride = 2;
for (i = 0; i < m; i++) {
    BLASLONG base_a = i * stride;
    BLASLONG base_b = i * 3; // Non-unit write stride for variation
    a1 = *(a_offset + base_a);
    a2 = *(a_offset + base_a + 1);
    *(b + base_b) = a1 + a2;
}
}
