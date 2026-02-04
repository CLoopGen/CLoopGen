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
    x = 1.5;
    mu = 0.5;
    N = 10000000;  // Adjusted to achieve ~0.01 sec runtime on modern CPU
    Ynm1 = 1.0;
    Yn = 2.0 * (mu + 1) / x * Yn - Ynm1;
}