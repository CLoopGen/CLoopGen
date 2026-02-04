#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double w87a[21];
double savfun[21];
double res87;
int k;

void init_vars() {
    for (int i = 0; i < 21; i++) {
        w87a[i] = 1.0 + i * 0.1;
        savfun[i] = 2.0 - i * 0.2;
    }
    res87 = 0.0;
    k = 0;
}