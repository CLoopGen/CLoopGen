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
        temp = alpha; // Introduce temporary to create artificial dependency
        for (j = 0; j < n2; j++) {
            temp = B[ldb * i + j] * temp; // RAW: temp depends on previous iteration
            B[ldb * i + j] = temp;       // WAW: Write after write on B element
            temp = alpha;                // Reset to break carry-forward beyond one element
        }
    }
}
