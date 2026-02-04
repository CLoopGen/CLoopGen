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
    i = chunk;
    if (i > 0) {
        do {
            *(c_offset1 + 0) *= beta;
            *(c_offset1 + 1) *= beta;
            *(c_offset1 + 2) *= beta;
            *(c_offset1 + 3) *= beta;
            *(c_offset1 + 4) *= beta;
            *(c_offset1 + 5) *= beta;
            *(c_offset1 + 6) *= beta;
            *(c_offset1 + 7) *= beta;
            c_offset1 += 8;
            i--;
        } while (i > 0);
    }
    i = remain;
    if (i > 0) {
        *c_offset1 *= beta;
        c_offset1++;
        i--;
        for (; i > 0; i--) {
            *c_offset1 *= beta;
            c_offset1++;
        }
    }
}
}
