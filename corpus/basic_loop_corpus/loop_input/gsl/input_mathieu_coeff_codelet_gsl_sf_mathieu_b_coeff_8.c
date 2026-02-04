#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double coeff[100];
int ii;
double sum;

void init_vars() {
    for (ii = 0; ii < 100; ii++) {
        coeff[ii] = (double)(ii + 1) * 1.5;
    }
    sum = 42.0;
    ii = 0;
}