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
    double temp;
    for (i = 0; i < n1; i++) {
        temp = alpha; // Introduce temporary to create WAW-like non-carried dep (redundant but structurally different)
        for (j = 0; j < n2; j++) {
            temp = B[ldb * i + j] * alpha; // Remove direct write, use temp to break WAW across iterations
            B[ldb * i + j] = temp;         // Reintroduce store with intermediate dependency (RAW on temp)
        }
    }
}
