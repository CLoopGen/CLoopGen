#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int time_repeat = 1000000;
double *t;
int iter = 1000;
int k;

void init_vars() {
    t = (double *)calloc(time_repeat, sizeof(double));
    if (!t) {
        exit(1);
    }
    for (int i = 0; i < time_repeat; ++i) {
        t[i] = 1.0;
    }
}