#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int m;
double p_mm;
double root_factor;
double fact_coeff;
int i;

void init_vars() {
    m = 10000000;  // Adjusted for ~0.01 sec runtime on modern CPU
    p_mm = 1.0;
    root_factor = sqrt(2.0);
    fact_coeff = 1.0;
    i = 0;
}