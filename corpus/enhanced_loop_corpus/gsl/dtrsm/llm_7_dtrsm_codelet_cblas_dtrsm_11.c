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
    double *base_B = &B[0];
    for (i = 0; i < n1; i++) {
        double local_alpha = alpha;
        double factor = local_alpha * local_alpha; // Break direct use of alpha
        for (j = 0; j < n2; j += 2) {
            if (j + 1 < n2) {
                // Unroll and modify access pattern to remove immediate loop-carried dependencies
                B[ldb * i + j] *= factor;
                B[ldb * i + j + 1] *= factor;
            } else {
                B[ldb * i + j] *= local_alpha;
            }
        }
    }
}
