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
    // Reduced computational intensity: unroll less and reduce memory operations per iteration
    for (ii = 0; ii < i; ii++) {
        // Only write first four elements per iteration, reducing work
        b[0] = a01[0];
        b[1] = a02[0];
        b[2] = a03[0];
        b[3] = a04[0];

        // Advance pointers by one data unit only
        a01 += 1;
        a02 += 1;
        a03 += 1;
        a04 += 1;
        b += 4;  // Smaller stride in output
    }
}
