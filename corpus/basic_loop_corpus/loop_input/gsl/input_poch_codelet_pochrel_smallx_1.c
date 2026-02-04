#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double bern[21];
double x;
double poly1;
int nterms;
double var2;
double rho;
double term;
double gbern[24];
int k;
int j;

void init_vars() {
    nterms = 20;
    x = 1.5;
    var2 = 0.5;
    rho = 0.25;
    poly1 = 1.0;
    term = 1.0;

    for (int i = 0; i < 21; i++) {
        bern[i] = sin(i + 1);
    }
    for (int i = 0; i < 24; i++) {
        gbern[i] = cos(i + 1);
    }

    k = 0;
    j = 0;
}