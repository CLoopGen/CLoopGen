#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int m = 1000000;
double lambda = 1.25;
double xi = 0.75;
double Pkp1 = 1.0;
double Pk = 0.5;
double Pkm1 = 0.0;
int k;

void init_vars() {
    // No additional initialization needed for scalar variables
    // All scalars are already initialized at file scope
}