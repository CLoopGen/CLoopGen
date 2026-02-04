#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
extern double *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n1; i++) {
        double local_alpha = alpha; // Local copy to remove potential aliasing effects
        for (j = 0; j < n2 - 1; j += 2) {
            // Unroll by 2 and remove loop-carried dependencies
            B[ldb * i + j] *= local_alpha;
            B[ldb * i + j + 1] *= local_alpha;
        }
        // Handle odd-sized n2
        if (j < n2) {
            B[ldb * i + j] *= local_alpha;
        }
    }
}
