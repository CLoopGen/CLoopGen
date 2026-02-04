#include <stdio.h>
#include <inttypes.h>

int tsteps = 100;
int n = 2000;
double A[2000];
double B[2000];
int t;
int i;

void init_vars() {
    for (int j = 0; j < n; j++) {
        A[j] = (double)(j % 100) / 10.0;
        B[j] = 0.0;
    }
}