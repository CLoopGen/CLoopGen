#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double qcoeff[101];
int i;
int k;
int n;

void init_vars() {
    n = 100; 

    for (int idx = 0; idx <= n; idx++) {
        qcoeff[idx] = 1.0 + idx * 0.1;
    }
}