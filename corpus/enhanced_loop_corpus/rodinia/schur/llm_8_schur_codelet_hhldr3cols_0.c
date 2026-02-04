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
    // Variant 1: Increased computational intensity by unrolling the loop 2x and increasing arithmetic operations
    // Also modifies trip count to process only even indices, effectively reducing iterations but increasing work per iteration
    int j;
    for (j = j0; j < n; j += 2) {
        double ip1, ip2, prod1, prod2;
        // First iteration (j)
        ip1 = nu1 * ((A)->me[k][j]) + nu2 * ((A)->me[k + 1][j]) + nu3 * ((A)->me[k + 2][j]);
        prod1 = ip1 * beta;
        ((A)->me[k][j] += (-prod1 * nu1));
        ((A)->me[k + 1][j] += (-prod1 * nu2));
        ((A)->me[k + 2][j] += (-prod1 * nu3));

        // Second iteration (j+1), if within bounds
        if (j + 1 < n) {
            ip2 = nu1 * ((A)->me[k][j + 1]) + nu2 * ((A)->me[k + 1][j + 1]) + nu3 * ((A)->me[k + 2][j + 1]);
            prod2 = ip2 * beta;
            ((A)->me[k][j + 1] += (-prod2 * nu1));
            ((A)->me[k + 1][j + 1] += (-prod2 * nu2));
            ((A)->me[k + 2][j + 1] += (-prod2 * nu3));
        }
    }
}
