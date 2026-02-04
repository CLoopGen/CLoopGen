#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double a;
extern  double b;
extern  double x;
extern double Mnm1;
extern double Mn;
extern double Mnp1;
extern double n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *Mn_arr = (double*)malloc(3 * sizeof(double));
    Mn_arr[0] = Mnm1;
    Mn_arr[1] = Mn;
    for (n = a + 1.; n < b - 0.5; n += 1.) {
        int idx_prev = ((int)(n - a)) % 3;
        int idx_curr = (idx_prev + 1) % 3;
        int idx_next = (idx_curr + 1) % 3;
        Mn_arr[idx_next] = ((b - n) * Mn_arr[idx_prev] + (2 * n - b + x) * Mn_arr[idx_curr]) / n;
        Mn_arr[idx_prev] = Mn_arr[idx_curr];
        Mn_arr[idx_curr] = Mn_arr[idx_next];
    }
    Mnm1 = Mn_arr[(int)(n - a - 1) % 3];
    Mn = Mn_arr[(int)(n - a) % 3];
    free(Mn_arr);
}
