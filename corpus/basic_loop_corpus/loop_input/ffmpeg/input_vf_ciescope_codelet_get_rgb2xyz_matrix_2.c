#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double m[3][3];
double S[3];
double X[4];
double Z[4];
int i;

void init_vars() {
    for (int idx = 0; idx < 3; ++idx) {
        for (int jdx = 0; jdx < 3; ++jdx) {
            m[idx][jdx] = (double)(idx * 3 + jdx + 1);
        }
        S[idx] = 0.0;
    }
    for (int idx = 0; idx < 4; ++idx) {
        X[idx] = (double)(idx + 1);
        Z[idx] = (double)(idx + 2);
    }
    i = 0;
}