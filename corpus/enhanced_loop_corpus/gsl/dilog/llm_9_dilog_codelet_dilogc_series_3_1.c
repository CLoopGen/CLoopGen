#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double a;
extern double H_re[7];
extern double H_im[7];
extern double an;
extern double nfact;
extern double sum_re;
extern double sum_im;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp_re[7] = {0};
double temp_im[7] = {0};
for (n = 1; n <= 3; n++) {
    double t1, t2;
    an *= a;
    nfact *= n;
    t1 = an / nfact;
    temp_re[n] = t1 * H_re[n];
    temp_im[n] = t1 * H_im[n];

    an *= a;
    nfact *= (n + 1);
    t2 = an / nfact;
    temp_re[n+1] = t2 * H_re[n+1];
    temp_im[n+1] = t2 * H_im[n+1];
}
for (n = 1; n <= 6; n++) {
    sum_re += temp_re[n];
    sum_im += temp_im[n];
}
}
