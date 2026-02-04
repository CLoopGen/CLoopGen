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
    BLASLONG offset_vector[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    for (i = chunk; i > 0; i--) {
        for (BLASLONG k = 0; k < 8; k++) {
            *(c_offset1 + offset_vector[k]) *= beta;
        }
        c_offset1 += 8;
    }
    for (i = remain; i > 0; i--) {
        *c_offset1 *= beta;
        c_offset1++;
    }
}
}
