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
    // Variant 1: Strided Memory Access (column-major traversal with stride of 1 in j, but access B with positive stride)
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            B[ldb * i + j] *= alpha;
        }
    }
}
