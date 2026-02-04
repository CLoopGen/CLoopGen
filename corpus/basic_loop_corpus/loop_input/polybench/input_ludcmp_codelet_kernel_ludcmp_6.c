#include <stdio.h>
#include <inttypes.h>

int n = 2000;

double A[2000][2000];
double b[2000];
double y[2000];
int i;
int j;
double w;

void init_vars() {
    for (int idx = 0; idx < 2000; idx++) {
        b[idx] = 1.0 + idx * 0.1;
        y[idx] = 0.0;
        for (int jdx = 0; jdx < 2000; jdx++) {
            A[idx][jdx] = (idx == jdx) ? 1.0 : 0.01 / (1.0 + idx + jdx);
        }
    }
}