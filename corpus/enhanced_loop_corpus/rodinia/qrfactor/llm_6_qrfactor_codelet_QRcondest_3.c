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

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern MAT *QR;
extern VEC *y;
extern double sum;
extern int i;
extern int j;
extern int limit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (i = limit - 1; i >= 0; i--) {
        sum = 0.;
        temp = 0.;
        for (j = i + 1; j < limit; j++) {
            temp += QR->me[i][j] * y->ve[j];
        }
        sum = temp;
        y->ve[i] = (sum >= 0.) ? 1. : -1.;
        if (QR->me[i][i] < 0.) {
            y->ve[i] = -y->ve[i];
        }
    }
}
