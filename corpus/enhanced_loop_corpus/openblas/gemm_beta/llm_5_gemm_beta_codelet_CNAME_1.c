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
        BLASLONG offset = 0;
        for (BLASLONG k = 0; k < 8; k++) {
            if (k < 8) {
                *(c_offset1 + offset) *= beta;
                offset++;
            }
        }
        c_offset1 += 8;
    }
    i = remain;
    if (i == 0) continue;
    do {
        *c_offset1 *= beta;
        c_offset1++;
        i--;
    } while (i > 0);
}
}
