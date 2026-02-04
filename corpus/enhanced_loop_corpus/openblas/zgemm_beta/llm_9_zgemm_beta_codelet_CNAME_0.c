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
BLASLONG block_size = 16;
for (j = 0; j < n; j++) {
    c_offset1 = c_offset + j * ldc;
    for (i = 0; i < m; i += block_size) {
        BLASLONG remaining = (m - i) < block_size ? (m - i) : block_size;
        for (BLASLONG k = 0; k < remaining; k++) {
            *(c_offset1 + i + k) = 0.F;
        }
    }
}
}
