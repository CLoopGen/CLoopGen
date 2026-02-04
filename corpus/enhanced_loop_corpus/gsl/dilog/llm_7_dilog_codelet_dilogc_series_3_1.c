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
double prev_H_re, prev_H_im;
prev_H_re = H_re[1];
prev_H_im = H_im[1];
an *= a;
nfact *= 1;
double t = an / nfact;
sum_re += t * prev_H_re;
sum_im += t * prev_H_im;

for (n = 2; n <= 6; n++) {
    double curr_H_re = H_re[n] + prev_H_re;
    double curr_H_im = H_im[n] + prev_H_im;
    an *= a;
    nfact *= n;
    t = an / nfact;
    sum_re += t * curr_H_re;
    sum_im += t * curr_H_im;
    prev_H_re = curr_H_re;
    prev_H_im = curr_H_im;
}
}
