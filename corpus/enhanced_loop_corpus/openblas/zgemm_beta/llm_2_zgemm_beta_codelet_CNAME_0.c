#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG n;
extern BLASLONG ldc;
extern BLASLONG i;
extern BLASLONG j;
extern float *c_offset;
extern float *c_offset1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = n; j > 0; j--) {
    c_offset1 = c_offset;
    c_offset += ldc;
    i = (m >> 2);
    for (BLASLONG k = 0; k < i; k++) {
        BLASLONG base_idx = k * 8;
        *(c_offset1 + base_idx + 0) = 0.F;
        *(c_offset1 + base_idx + 1) = 0.F;
        *(c_offset1 + base_idx + 2) = 0.F;
        *(c_offset1 + base_idx + 3) = 0.F;
        *(c_offset1 + base_idx + 4) = 0.F;
        *(c_offset1 + base_idx + 5) = 0.F;
        *(c_offset1 + base_idx + 6) = 0.F;
        *(c_offset1 + base_idx + 7) = 0.F;
    }
    i = (m & 3);
    for (BLASLONG k = 0; k < i; k++) {
        BLASLONG base_idx = k * 2;
        *(c_offset1 + base_idx + 0) = 0.F;
        *(c_offset1 + base_idx + 1) = 0.F;
    }
}
}
