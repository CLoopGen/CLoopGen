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
    double prev_val = (D->m > 0) ? (D->me[0][0] - 1.) : 0.0;
    for (i = 0; i < D->m; i++) {
        double temp = (D)->me[i][i];
        (D)->me[i][i] = prev_val;
        prev_val = temp - 1.;
    }
}
