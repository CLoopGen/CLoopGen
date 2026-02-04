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
    for (int j = 0; j < 3; j++) {
        S[j] = 1.0 + j;
        X[j] = 2.0 + j;
        Z[j] = 3.0 + j;
    }
    X[3] = 5.0;
    Z[3] = 6.0;
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            m[j][k] = 0.0;
        }
    }
    i = 0;
}