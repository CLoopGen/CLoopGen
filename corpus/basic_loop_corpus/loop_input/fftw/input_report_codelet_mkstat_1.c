#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int j;
double *t;
int st;

void init_vars() {
    st = 10000;
    t = (double*)aligned_alloc(32, st * sizeof(double));
    for (int idx = 0; idx < st; ++idx) {
        t[idx] = (double)(st - idx);
    }
}