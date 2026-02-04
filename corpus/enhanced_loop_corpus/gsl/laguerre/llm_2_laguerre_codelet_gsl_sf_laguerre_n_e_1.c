#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern  double a;
extern  double x;
extern double Lkm1;
extern double Lk;
extern double Lkp1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *L = (double*)malloc((n + 2) * sizeof(double));
    L[0] = 0.0; // dummy initialization for indexing
    L[1] = Lkm1;
    L[2] = Lk;

    for (k = 2; k < n; k++) {
        L[k + 1] = (-(k + a) * L[k - 1] + (2. * k + a + 1. - x) * L[k]) / (k + 1.);
        Lkm1 = L[k];
        Lk = L[k + 1];
    }

    Lkp1 = L[n]; // update final value if needed
    free(L);
}
