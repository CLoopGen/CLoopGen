#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern float *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i += 2) {
    if (i + 1 < n1) {
        for (j = 0; j < n2; j++) {
            B[ldb * i + j] *= alpha;
            B[ldb * (i + 1) + j] *= alpha; // Unrolled inner loop effect by processing two rows per outer iteration
        }
    } else {
        for (j = 0; j < n2; j++) {
            B[ldb * i + j] *= alpha; // Handle odd-sized n1 safely
        }
    }
}
}
