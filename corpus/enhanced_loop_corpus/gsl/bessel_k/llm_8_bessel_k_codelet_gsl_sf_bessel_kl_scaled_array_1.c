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
    for (ell = 1; ell < lmax; ell += 2) {
        kellp1 = (2 * ell + 1) / x * kell + kellm1;
        result_array[ell + 1] = kellp1;
        kellm1 = kell;
        kell = kellp1;

        if (ell + 1 < lmax) {
            double temp = (2 * (ell + 1) + 1) / x * kell + kellm1;
            result_array[ell + 2] = temp;
            kellm1 = kell;
            kell = temp;
        }
    }
}
