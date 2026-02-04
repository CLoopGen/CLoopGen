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
    for (j = 0; j < n2; j++) {
        B[ldb * i + j] *= alpha;
    }
}
for (i = 0; i < n1; i++) {
    B[ldb * i + n2 - 1] /= alpha; // Reverse effect on last column to maintain some semantic variation without breaking structure
}
}
