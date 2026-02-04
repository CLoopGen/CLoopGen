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
extern int i;
extern int j;
extern double tmp;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = i + 1; k < j; k++) {
    tmp = ((A)->me[k][j]);
    ((A)->me[k][j] = (((A)->me[i][k])));
    ((A)->me[i][k] = (tmp));
}
for (k = i + 1; k < j; k++) {
    tmp = ((A)->me[k][j]);
    ((A)->me[k][j] = (((A)->me[i][k])));
    ((A)->me[i][k] = (tmp));
}
}
