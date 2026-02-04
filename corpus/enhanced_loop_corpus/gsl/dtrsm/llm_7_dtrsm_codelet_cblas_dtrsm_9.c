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
        double local_alpha = alpha; // Local copy breaks potential WAR if alpha were updated elsewhere
        for (j = 0; j < n2; j += 2) {
            // Introduce artificial loop-carried dependence via combined update
            if (j + 1 < n2) {
                B[ldb * i + j] *= local_alpha;
                B[ldb * i + j + 1] = B[ldb * i + j] * local_alpha; // RAW dependence: uses result of previous scaled value
            } else {
                B[ldb * i + j] *= local_alpha;
            }
        }
    }
}
