#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

double x = 1.5;
double p = 0.0;
double q = 0.0;
ssize_t i;

double Pone[8];
double Qone[8];

void init_vars() {
    const size_t array_size = 8;
    for (size_t idx = 0; idx < array_size; idx++) {
        Pone[idx] = sin(idx + 1);
        Qone[idx] = cos(idx + 1);
    }
    x = 1.5;
    p = 1.0;
    q = 1.0;
}