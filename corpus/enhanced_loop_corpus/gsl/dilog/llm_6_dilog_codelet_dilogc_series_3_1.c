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
double temp_re = sum_re;
double temp_im = sum_im;
double an_local = an;
double nfact_local = nfact;
for (n = 1; n <= 6; n++) {
    double t;
    an_local *= a;
    nfact_local *= n;
    t = an_local / nfact_local;
    temp_re += t * H_re[n];
    temp_im += t * H_im[n];
}
sum_re = temp_re;
sum_im = temp_im;
}
