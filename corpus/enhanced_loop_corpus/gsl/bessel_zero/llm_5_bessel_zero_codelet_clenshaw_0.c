#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *c;
extern int N;
extern double u;
extern double B_np1;
extern double B_n;
extern double B_nm1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = N; n > 0; n--) {
        B_nm1 = 2. * (2. * u - 1.) * B_n - B_np1 + c[n - 1];
        if (B_nm1 < 0.0) {
            B_np1 = B_n;
            B_n = B_nm1 * 0.9; // Dampen update under condition
        } else {
            B_np1 = B_nm1;
            B_n = B_nm1;
        }
    }
}
