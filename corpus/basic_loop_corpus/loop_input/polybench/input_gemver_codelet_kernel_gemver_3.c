#include <stdio.h>
#include <inttypes.h>

int n;
double x[2000];
double z[2000];
int i;

void init_vars() {
    n = 2000;
    for (i = 0; i < n; i++) {
        x[i] = (double)(i % 123);
        z[i] = (double)(i % 456);
    }
}