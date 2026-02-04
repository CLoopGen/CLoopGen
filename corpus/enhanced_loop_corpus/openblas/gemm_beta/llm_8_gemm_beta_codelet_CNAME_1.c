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
for (j = n; j > 0; j -= 2) {
    c_offset1 = c_offset;
    for (i = chunk; i > 0; i--) {
        *(c_offset1 + 0) *= beta;
        *(c_offset1 + 1) *= beta;
        *(c_offset1 + 2) *= beta;
        *(c_offset1 + 3) *= beta;
        *(c_offset1 + 4) *= beta;
        *(c_offset1 + 5) *= beta;
        *(c_offset1 + 6) *= beta;
        *(c_offset1 + 7) *= beta;
        *(c_offset1 + 8) *= beta;
        *(c_offset1 + 9) *= beta;
        *(c_offset1 + 10) *= beta;
        *(c_offset1 + 11) *= beta;
        *(c_offset1 + 12) *= beta;
        *(c_offset1 + 13) *= beta;
        *(c_offset1 + 14) *= beta;
        *(c_offset1 + 15) *= beta;
        c_offset1 += 16;
    }
    for (i = remain; i > 0; i--) {
        *c_offset1 *= beta;
        c_offset1++;
    }
    c_offset += ldc * 2;
}
}
