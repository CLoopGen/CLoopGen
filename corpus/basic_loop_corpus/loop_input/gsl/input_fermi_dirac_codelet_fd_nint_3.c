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
    // Initialize scalar variables
    a = 1.5;
    f = 0.0;
    n = 100;  // Ensures loop runs from i = 99 down to 1 (valid access for qcoeff[1] to qcoeff[99])

    // Initialize qcoeff array
    for (int j = 0; j < 101; j++) {
        qcoeff[j] = (double)(j % 100) / 10.0;
    }
}