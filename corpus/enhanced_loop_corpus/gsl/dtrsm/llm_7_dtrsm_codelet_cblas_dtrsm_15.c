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
        for (j = 0; j < n2; j += 2) {
            if (j + 1 < n2) {
                B[ldb * i + j] *= alpha;
                B[ldb * i + j + 1] *= alpha;
            } else {
                B[ldb * i + j] *= alpha;
            }
        }
    }
}
