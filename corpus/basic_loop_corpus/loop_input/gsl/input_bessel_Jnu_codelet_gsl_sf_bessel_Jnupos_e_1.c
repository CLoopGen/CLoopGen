#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double x;
int N;
double mu;
double Jnp1;
double Jn;
double Jnm1;
int n;

void init_vars() {
    x = 5.7;
    mu = 1.3;
    Jnp1 = 0.8;
    Jn = 0.6;
    Jnm1 = 0.0;
    N = 10000000;  // Large enough to take ~0.01 seconds on modern CPU
}