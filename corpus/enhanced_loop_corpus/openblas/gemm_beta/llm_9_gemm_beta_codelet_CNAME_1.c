#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG n;
extern float beta;
extern BLASLONG ldc;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG chunk;
extern BLASLONG remain;
extern float *c_offset1;
extern float *c_offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = n; j > 0; j--) {
    c_offset1 = c_offset;
    c_offset += ldc;
    for (i = chunk / 2; i > 0; i--) {
        *(c_offset1 + 0) = *(c_offset1 + 0) * beta + 1.0f;
        *(c_offset1 + 1) = *(c_offset1 + 1) * beta + 1.0f;
        *(c_offset1 + 2) = *(c_offset1 + 2) * beta + 1.0f;
        *(c_offset1 + 3) = *(c_offset1 + 3) * beta + 1.0f;
        *(c_offset1 + 4) = *(c_offset1 + 4) * beta + 1.0f;
        *(c_offset1 + 5) = *(c_offset1 + 5) * beta + 1.0f;
        *(c_offset1 + 6) = *(c_offset1 + 6) * beta + 1.0f;
        *(c_offset1 + 7) = *(c_offset1 + 7) * beta + 1.0f;
        c_offset1 += 8;
    }
    for (i = remain; i > 0; i--) {
        *c_offset1 = *c_offset1 * beta + 1.0f;
        c_offset1++;
    }
}
}
