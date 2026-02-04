#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int l = 1000000;
double lambda = 0.5;
double x = 1.0;
double c = 0.25;
double Pellm1 = 1.0;
double Pell = 0.5;
double Pellp1;
int ell;

void init_vars() {
    // No dynamic data to initialize; all variables are scalar and initialized at file scope
}