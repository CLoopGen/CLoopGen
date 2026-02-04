#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int m;
extern int n;
extern int _usr_j0;
extern double alpha;
extern double **A;
extern double *x;
extern double *y;
extern int i;
extern int j;
extern int n4;
extern double *Aref;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0



void loop(){
for (i = 0; i < m; i++) {
    tmp = alpha * x[i];
    Aref = &(A[i][j0]);
    for (j = 0; j < n4; j++) {
        double ty0 = y[4 * j], ty1 = y[4 * j + 1];
        double ty2 = y[4 * j + 2], ty3 = y[4 * j + 3];
        double product0 = tmp * ty0;
        double product1 = tmp * ty1;
        double product2 = tmp * ty2;
        double product3 = tmp * ty3;
        Aref[4 * j] += product0;
        Aref[4 * j + 1] += product1;
        Aref[4 * j + 2] += product2;
        Aref[4 * j + 3] += product3;
    }
    Aref += 4 * n4;
    y += 4 * n4;
    for (j = 0; j < n; j++) {
        double delayed_product = tmp * y[j];
        Aref[j] += delayed_product;
    }
}
}
