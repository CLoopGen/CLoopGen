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
    // Variant 2: Consecutive memory access by flattening the 2D index into a linear traversal
    int total_elements = n1 * n2;
    for (int idx = 0; idx < total_elements; idx++) {
        B[idx] *= alpha;
    }
}
