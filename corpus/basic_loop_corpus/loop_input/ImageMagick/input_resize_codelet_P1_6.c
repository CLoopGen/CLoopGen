#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

double x = 16.0;
double p = 1.0;
double q = 1.0;
ssize_t i;

double Pone[5];
double Qone[5];

void init_vars() {
    for (int idx = 0; idx < 5; idx++) {
        Pone[idx] = 1.0 / (idx + 1);
        Qone[idx] = 2.0 / (idx + 1);
    }
}