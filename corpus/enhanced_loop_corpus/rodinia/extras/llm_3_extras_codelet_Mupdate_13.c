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
        int idx = 4 * j;
        Aref[idx]     += tmp * y[idx];
        Aref[idx + 1] += tmp * y[idx + 1];
        Aref[idx + 2] += tmp * y[idx + 2];
        Aref[idx + 3] += tmp * y[idx + 3];
    }
    Aref += 4 * n4;
    y += 4 * n4;
    for (j = 0; j < n; j += 2) {
        Aref[j] += tmp * y[j];
        if (j + 1 < n)
            Aref[j + 1] += tmp * y[j + 1];
    }
}
}
