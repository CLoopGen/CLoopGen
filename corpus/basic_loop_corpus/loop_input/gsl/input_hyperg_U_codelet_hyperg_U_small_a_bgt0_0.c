#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double a = 2.5;
double b = 1000000.0;
double x = 1.5;
double b0 = 0.0;
double Ubm1 = 1.0;
double Ub = 1.0;
double Ubp1;
double bp;

void init_vars() {
    a = 2.5;
    b = 1000000.0;
    x = 1.5;
    b0 = 0.0;
    Ubm1 = 1.0;
    Ub = 1.0;
    Ubp1 = 0.0;
    bp = 0.0;
}