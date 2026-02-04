#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int l;
double x;
double Qellp1;
double Qell;
double Qellm1;
int ell;

void init_vars() {
    l = 1000000;
    x = 1.5;
    Qellp1 = 1.0;
    Qell = 0.5;
    Qellm1 = 0.0;
}