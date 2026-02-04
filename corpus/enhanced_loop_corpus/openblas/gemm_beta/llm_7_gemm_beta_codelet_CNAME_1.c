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
float prev_beta = 1.0f;
for (j = n; j > 0; j--) {
    c_offset1 = c_offset;
    c_offset += ldc;
    float local_beta = beta * prev_beta;
    for (i = chunk; i > 0; i--) {
        *(c_offset1 + 0) *= local_beta;
        *(c_offset1 + 1) *= local_beta;
        *(c_offset1 + 2) *= local_beta;
        *(c_offset1 + 3) *= local_beta;
        *(c_offset1 + 4) *= local_beta;
        *(c_offset1 + 5) *= local_beta;
        *(c_offset1 + 6) *= local_beta;
        *(c_offset1 + 7) *= local_beta;
        c_offset1 += 8;
    }
    for (i = remain; i > 0; i--) {
        *c_offset1 *= local_beta;
        c_offset1++;
    }
    prev_beta = local_beta;
}
}
