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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < A->m; i++) {
        double sum = 0.0;
        for (j = 0; j < i; j++) {
            (A)->me[i][j] = (A)->me[j][i] + (A)->me[j][0]; 
            sum += (A)->me[i][j];
        }
        (A)->me[i][0] = sum / i; 
    }
}
