#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int l = 1000000;
double lambda = 1.5;
double xi = 0.8;
double Pellp1 = 1.0;
double Pell = 0.5;
double Pellm1 = 0.0;
int ell;

void init_vars() {
    l = 1000000;
    lambda = 1.5;
    xi = 0.8;
    Pellp1 = 1.0;
    Pell = 0.5;
    Pellm1 = 0.0;
}