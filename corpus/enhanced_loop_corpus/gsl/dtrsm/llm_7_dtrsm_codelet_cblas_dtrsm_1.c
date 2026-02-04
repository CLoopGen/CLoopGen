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
    if (alpha == 1.0) return;
    for (i = 0; i < n1; i++) {
        for (j = 1; j < n2; j++) {
            B[ldb * i + j] *= alpha;
        }
        if (n2 > 0) {
            B[ldb * i] *= alpha;
        }
    }
}
