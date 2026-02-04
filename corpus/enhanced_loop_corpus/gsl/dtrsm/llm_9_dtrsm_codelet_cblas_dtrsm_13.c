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
    for (j = 0; j < n2; j += 2) {
        if (i < n1) {
            B[ldb * i + j] *= alpha;
            if (j + 1 < n2) {
                B[ldb * i + (j + 1)] *= alpha;
            }
        }
        if (i + 1 < n1) {
            B[ldb * (i + 1) + j] *= alpha;
            if (j + 1 < n2) {
                B[ldb * (i + 1) + (j + 1)] *= alpha;
            }
        }
    }
}
}
