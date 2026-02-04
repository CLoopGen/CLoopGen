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
extern int m4;
extern int n2;
extern double *Aref;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0



void loop(){
for (j = 0; j < n; j++) {
    tmp = alpha * x[2 * n2 + j];
    Aref = &(A[2 * n2 + j][j0]);
    i = 0;
    if (m4 > 0) {
        do {
            y[4 * i] += tmp * Aref[4 * i];
            y[4 * i + 1] += tmp * Aref[4 * i + 1];
            y[4 * i + 2] += tmp * Aref[4 * i + 2];
            y[4 * i + 3] += tmp * Aref[4 * i + 3];
            i++;
        } while (i < m4);
    }
    for (i = 0; i < m; i++) {
        y[4 * m4 + i] += tmp * Aref[4 * m4 + i];
    }
}
}
