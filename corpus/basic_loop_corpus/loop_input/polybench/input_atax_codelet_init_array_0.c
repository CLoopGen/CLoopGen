#include <stdio.h>
#include <inttypes.h>

int n;
double x[2100];
int i;
double fn;

void init_vars() {
    n = 2100;
    fn = 100.0;
    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }
}