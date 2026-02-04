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
    double local_accum = 1.0;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j += 2) {
            // Unroll-like pattern with no loop-carried dependency
            // Independent operations introduced via grouping
            if (j + 1 < n2) {
                B[ldb * i + j] *= alpha;
                B[ldb * i + j + 1] *= alpha;
            } else {
                B[ldb * i + j] *= alpha;
            }
            // Eliminated inter-iteration dependencies: each pair is independent
            // No value carried from one j iteration to next -> enables parallelization
        }
    }
    // Use local_accum to prevent dead code elimination
    asm volatile("" : "+r"(local_accum));
}
