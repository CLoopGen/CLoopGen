#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  double x;
extern double *result_array;
extern int ell;
extern double kellp1;
extern double kell;
extern double kellm1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (lmax > 1) {
        for (ell = 1; ell < lmax; ell++) {
            for (int unroll_factor = 0; unroll_factor < 1; unroll_factor++) {
                kellp1 = (2 * ell + 1) / x * kell + kellm1;
                result_array[ell + 1] = kellp1;
                kellm1 = kell;
                kell = kellp1;
            }
        }
    }
}
