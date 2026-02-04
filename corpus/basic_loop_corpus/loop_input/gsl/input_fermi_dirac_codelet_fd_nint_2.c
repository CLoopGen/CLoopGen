#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double qcoeff[101];
double a;
double f;
int i;
int n;

void init_vars() {
    n = 100; 
    a = 1.0003;
    f = 0.5;
    for (int j = 0; j <= n; j++) {
        qcoeff[j] = (double)(j % 7 + 1);
    }
}