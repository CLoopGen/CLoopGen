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
    // Variant 2: Consecutive memory access with pointer arithmetic to enhance spatial locality
    double *b_ptr = B;
    for (i = 0; i < n1; i++) {
        double *row_start = b_ptr + ldb * i;
        for (j = 0; j < n2; j++) {
            row_start[j] *= alpha;
        }
    }
}
