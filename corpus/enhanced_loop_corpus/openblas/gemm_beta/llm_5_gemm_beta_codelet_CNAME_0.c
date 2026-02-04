#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG n;
extern BLASLONG ldc;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG chunk;
extern BLASLONG remain;
extern float *c_offset1;
extern float *c_offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = n; j > 0; j -= (ldc > n ? 1 : 1)) {
    c_offset1 = c_offset;
    c_offset += ldc;
    for (i = chunk; i > 0; i--) {
        const BLASLONG offset = i * 8;
        *(c_offset1 + offset - 8) = 0.F;
        *(c_offset1 + offset - 7) = 0.F;
        *(c_offset1 + offset - 6) = 0.F;
        *(c_offset1 + offset - 5) = 0.F;
        *(c_offset1 + offset - 4) = 0.F;
        *(c_offset1 + offset - 3) = 0.F;
        *(c_offset1 + offset - 2) = 0.F;
        *(c_offset1 + offset - 1) = 0.F;
    }
    if (remain >= 4) {
        *(c_offset1 + 0) = 0.F;
        *(c_offset1 + 1) = 0.F;
        *(c_offset1 + 2) = 0.F;
        *(c_offset1 + 3) = 0.F;
        c_offset1 += 4;
        for (i = remain - 4; i > 0; i--) {
            *c_offset1 = 0.F;
            c_offset1++;
        }
    } else {
        for (i = remain; i > 0; i--) {
            *c_offset1 = 0.F;
            c_offset1++;
        }
    }
}
}
