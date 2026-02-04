#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int n;
int k;
double y;
double k_term;
double sum1;

void init_vars() {
    n = 10000000;  // Large enough to take ~0.01s
    k = 0;
    y = 2.0;
    k_term = 1.0;
    sum1 = 0.0;
}