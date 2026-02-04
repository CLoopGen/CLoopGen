#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double a;
double H_re[7];
double H_im[7];
double an;
double nfact;
double sum_re;
double sum_im;
int n;

void init_vars() {
    a = 0.5;
    an = 1.0;
    nfact = 1.0;
    sum_re = 0.0;
    sum_im = 0.0;
    n = 0;

    for (int i = 0; i < 7; i++) {
        H_re[i] = sin(i + 1);
        H_im[i] = cos(i + 1);
    }
}