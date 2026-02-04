#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int m;
double lambda;
double xi;
double Pkp1;
double Pk;
double Pkm1;
int k;

void init_vars() {
    lambda = 1.234;
    xi = 0.567;
    Pkp1 = 1.0;
    Pk = 0.8;
    m = 1000000; 
}