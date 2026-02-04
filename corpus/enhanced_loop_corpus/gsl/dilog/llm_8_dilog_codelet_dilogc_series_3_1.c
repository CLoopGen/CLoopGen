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
for (n = 1; n <= 6; n += 2) {
    double t;
    an *= a;
    nfact *= n;
    if (n + 1 <= 6) {
        nfact *= (n + 1);
        an *= a;
    }
    t = an / nfact;
    sum_re += t * H_re[n];
    sum_im += t * H_im[n];
    if (n + 1 <= 6) {
        sum_re += t * H_re[n+1] / (n + 1);
        sum_im += t * H_im[n+1] / (n + 1);
    }
}
}
