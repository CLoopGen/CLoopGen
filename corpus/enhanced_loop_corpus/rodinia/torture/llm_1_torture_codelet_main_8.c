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

extern MAT *D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (D->m > 0) {
    i = 0;
    for (; i < D->m; i++)
        ((D)->me[i][i] = (((D)->me[i][i]) - 1.));
}
}
