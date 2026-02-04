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
extern int n;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (k = j + 1; k < n; k++) {
    tmp = ((A)->me[j][k]);
    ((A)->me[j][k] = (((A)->me[i][k])));
    ((A)->me[i][k] = (tmp));
}

}
