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
    ptrdiff_t stride = 2;
    double *base_L = (double*)aligned_alloc(32, (2 * n + 5) * sizeof(double));
    double *Lkm1_ptr = &base_L[0];
    double *Lk_ptr = &base_L[stride];
    double *Lkp1_ptr = &base_L[2 * stride];

    *Lkm1_ptr = Lkm1;
    *Lk_ptr = Lk;

    for (k = 2; k < n; k++) {
        *Lkp1_ptr = (-(k + a) * (*Lkm1_ptr) + (2. * k + a + 1. - x) * (*Lk_ptr)) / (k + 1.);
        Lkm1_ptr += stride;
        Lk_ptr += stride;
        Lkp1_ptr += stride;
    }

    Lkp1 = *(Lkp1_ptr - stride);
    Lk = *(Lk_ptr - stride);
    Lkm1 = *(Lkm1_ptr - stride);

    free(base_L);
}
