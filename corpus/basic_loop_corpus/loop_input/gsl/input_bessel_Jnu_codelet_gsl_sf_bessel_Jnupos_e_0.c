#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double x;
int N;
double mu;
double Ynm1;
double Yn;
double Ynp1;
int n;

void init_vars() {
    N = 10000000;  // Adjust to achieve ~0.01 sec runtime
    x = 2.0;
    mu = 0.5;
    Ynm1 = 1.0;
    Yn = 2.0 * (mu + 0) / x * Ynm1;  // Initial recurrence value for n=0
}