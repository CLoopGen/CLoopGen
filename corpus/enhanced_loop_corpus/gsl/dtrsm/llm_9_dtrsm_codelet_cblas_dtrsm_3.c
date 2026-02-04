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
for (i = 0; i < n1; i += 2) {
    for (j = 0; j < n2; j++) {
        if (i + 1 < n1) {
            B[ldb * i + j] *= alpha;
            B[ldb * (i + 1) + j] *= alpha;
        } else {
            B[ldb * i + j] *= alpha;
        }
    }
}
}
