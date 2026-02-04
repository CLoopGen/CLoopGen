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
    for (BLASLONG block = 0; block < (m >> 2); block++) {
        *(c_offset1 + 0) = 0.F;
        *(c_offset1 + 1) = 0.F;
        *(c_offset1 + 2) = 0.F;
        *(c_offset1 + 3) = 0.F;
        *(c_offset1 + 4) = 0.F;
        *(c_offset1 + 5) = 0.F;
        *(c_offset1 + 6) = 0.F;
        *(c_offset1 + 7) = 0.F;
        c_offset1 += 8;
    }
    for (BLASLONG rem = 0; rem < (m & 3); rem++) {
        *(c_offset1 + 0) = 0.F;
        *(c_offset1 + 1) = 0.F;
        c_offset1 += 2;
    }
}
}
