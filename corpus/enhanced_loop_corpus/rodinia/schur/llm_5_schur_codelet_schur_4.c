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

extern MAT *A;
extern int k;
extern int k_min;
extern int k_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = k_min; k <= k_max - 2; k++) {
    ((A)->me[k + 2][k] = (0.));
    if (k + 3 < (A)->max_m)
        ((A)->me[k + 3][k] = (0.));
}
}
