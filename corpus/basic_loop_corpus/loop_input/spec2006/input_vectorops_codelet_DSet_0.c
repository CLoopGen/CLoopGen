#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

double *vec;
int n;
double value;
int x;

void init_vars() {
    n = 16777216; // 16M elements * 8 bytes = 134MB, sufficient for ~0.01s on modern CPU
    vec = (double *)calloc(n, sizeof(double));
    if (!vec) {
        exit(1);
    }
    value = 3.14159;
    x = 0;
}