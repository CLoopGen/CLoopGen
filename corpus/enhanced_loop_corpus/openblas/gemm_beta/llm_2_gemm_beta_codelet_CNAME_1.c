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
    for (i = chunk; i > 0; i--) {
        float *base = c_offset1;
        *(base + 0*8) *= beta;
        *(base + 1*8) *= beta;
        *(base + 2*8) *= beta;
        *(base + 3*8) *= beta;
        *(base + 4*8) *= beta;
        *(base + 5*8) *= beta;
        *(base + 6*8) *= beta;
        *(base + 7*8) *= beta;
        c_offset1 += 8;
    }
    for (i = remain; i > 0; i--) {
        *c_offset1 *= beta;
        c_offset1++;
    }
}
}
