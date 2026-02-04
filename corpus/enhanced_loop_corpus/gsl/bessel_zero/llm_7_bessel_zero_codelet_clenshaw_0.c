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
    double prev_c = c[N - 1];
    for (n = N; n > 0; n--) {
        double current_c = (n > 1) ? c[n - 2] : 0.0;
        B_nm1 = 2. * (2. * u - 1.) * B_n - B_np1 + prev_c;
        prev_c = current_c;
        B_np1 = B_n;
        B_n = B_nm1;
    }
}
