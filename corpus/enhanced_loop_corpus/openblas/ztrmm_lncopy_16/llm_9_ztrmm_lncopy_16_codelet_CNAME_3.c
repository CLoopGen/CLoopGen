#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;
extern float *a05;
extern float *a06;
extern float *a07;
extern float *a08;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: unroll only partially and reduce memory operations
for (ii = 0; ii < i; ii++) {
    // Interleave fewer loads and stores to decrease arithmetic/memory pressure
    b[0] = *(a01 + 0);
    b[1] = *(a01 + 1);
    b[2] = *(a02 + 0);
    b[3] = *(a02 + 1);
    b[4] = *(a03 + 0);
    b[5] = *(a03 + 1);

    // Skip updating some pointers every iteration to simulate lighter workload
    if (ii % 2 == 0) {
        a04 += 2;
        a05 += 2;
        a06 += 2;
        a07 += 2;
        a08 += 2;
        b += 10;  // Adjusted offset to reflect reduced write size
    }

    a01 += 2;
    a02 += 2;
    a03 += 2;
    b += 6;
}
}
