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
    for (j = 0; j < n4; j += 2) {
        double y0 = y[4 * j], y1 = y[4 * j + 1], y2 = y[4 * j + 2], y3 = y[4 * j + 3];
        double y4 = y[4 * j + 4], y5 = y[4 * j + 5], y6 = y[4 * j + 6], y7 = y[4 * j + 7];
        Aref[4 * j] += tmp * y0;
        Aref[4 * j + 1] += tmp * y1;
        Aref[4 * j + 2] += tmp * y2;
        Aref[4 * j + 3] += tmp * y3;
        if (j + 1 < n4) {
            Aref[4 * j + 4] += tmp * y4;
            Aref[4 * j + 5] += tmp * y5;
            Aref[4 * j + 6] += tmp * y6;
            Aref[4 * j + 7] += tmp * y7;
        }
    }
    Aref += 4 * n4;
    y += 4 * n4;
    for (j = 0; j < n; j++)
        Aref[j] += tmp * y[j];
}
}
