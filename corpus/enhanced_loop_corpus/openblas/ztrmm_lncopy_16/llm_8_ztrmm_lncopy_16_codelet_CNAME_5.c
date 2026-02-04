#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii += 2) {
    if (ii + 1 < i) {
        // Unroll two iterations into one to increase computational intensity
        // First iteration
        b[0] = a01[0]; b[1] = a01[1];
        b[2] = a02[0]; b[3] = a02[1];
        b[4] = a03[0]; b[5] = a03[1];
        b[6] = a04[0]; b[7] = a04[1];

        // Second iteration
        b[8]  = a01[2]; b[9]  = a01[3];
        b[10] = a02[2]; b[11] = a02[3];
        b[12] = a03[2]; b[13] = a03[3];
        b[14] = a04[2]; b[15] = a04[3];

        a01 += 4;
        a02 += 4;
        a03 += 4;
        a04 += 4;
        b += 16;
    } else {
        // Handle remaining single iteration if i is odd
        b[0] = a01[0]; b[1] = a01[1];
        b[2] = a02[0]; b[3] = a02[1];
        b[4] = a03[0]; b[5] = a03[1];
        b[6] = a04[0]; b[7] = a04[1];
        a01 += 2;
        a02 += 2;
        a03 += 2;
        a04 += 2;
        b += 8;
    }
}
}
