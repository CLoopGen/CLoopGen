#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int m = 10000000;
double lambda = 1.5;
double x = 0.8;
double c = 0.3;
double Pkm1 = 1.0;
double Pk = 0.5;
double Pkp1;
int k;

void init_vars() {
    lambda = fabs(lambda);
    x = fabs(x);
    c = fabs(c);
    Pkm1 = 1.0;
    Pk = 0.5;
    m = 10000000;
}