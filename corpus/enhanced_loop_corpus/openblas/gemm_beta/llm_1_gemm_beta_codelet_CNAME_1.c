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
    BLASLONG total_iters = chunk * 8 + remain;
    for (i = total_iters; i > 0; i--) {
        *c_offset1 *= beta;
        c_offset1++;
    }
}
}
