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
    for (i = 0; i < n1; i++) {
        float local_alpha = alpha; // Break potential loop-carried dependency on alpha if it were modified elsewhere
        for (j = 0; j < n2; j += 2) { // Unroll by factor of 2 to introduce intra-iteration dependencies
            if (j + 1 < n2) {
                B[ldb * i + j] *= local_alpha;
                B[ldb * i + j + 1] *= local_alpha;
            } else {
                B[ldb * i + j] *= local_alpha;
            }
        }
    }
}
