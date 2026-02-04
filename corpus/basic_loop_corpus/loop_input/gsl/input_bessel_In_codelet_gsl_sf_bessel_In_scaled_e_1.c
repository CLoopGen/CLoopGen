#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int n;
double ax;
int nhi;
double Ikp1;
double Ik;
double Ikm1;
int k;

void init_vars() {
    n = 1000;
    ax = 1.5;
    nhi = 2000;
    Ikp1 = 1.0;
    Ik = 0.5;
    Ikm1 = 0.0;
    k = nhi;
}