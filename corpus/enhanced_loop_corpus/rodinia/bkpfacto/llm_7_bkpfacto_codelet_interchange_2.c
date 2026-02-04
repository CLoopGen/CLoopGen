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
    double temp_store[2] = {0};
    for (k = i + 1; k < j; k++) {
        temp_store[0] = ((A)->me[k][j]);
        temp_store[1] = ((A)->me[i][k]);
        ((A)->me[k][j]) = temp_store[1];
        ((A)->me[i][k]) = temp_store[0];
    }
}
