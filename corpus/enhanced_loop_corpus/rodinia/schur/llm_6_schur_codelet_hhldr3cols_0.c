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
extern int _usr_j0;
extern double beta;
extern double nu1;
extern double nu2;
extern double nu3;
extern double ip;
extern double prod;
extern int j;
extern int n;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0



void loop(){
    double temp_ip, temp_prod;
    for (j = j0; j < n; j++) {
        temp_ip = nu1 * ((A)->me[k][j]) + nu2 * ((A)->me[k + 1][j]) + nu3 * ((A)->me[k + 2][j]);
        temp_prod = temp_ip * beta;
        ((A)->me[k][j]) += (-temp_prod * nu1);
        ((A)->me[k + 1][j]) += (-temp_prod * nu2);
        ((A)->me[k + 2][j]) += (-temp_prod * nu3);
    }
}
