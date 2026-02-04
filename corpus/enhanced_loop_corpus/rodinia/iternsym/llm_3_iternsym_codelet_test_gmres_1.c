#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

extern int i;
extern MAT *R1;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed iteration order (backward traversal with stride > 1)
    // Access diagonal elements in reverse, using indirect indexing through pointer arithmetic
    double **me = R1->me;
    for (j = i; j >= 0; j--) {
        me[j][j] -= 1.;
    }
}
