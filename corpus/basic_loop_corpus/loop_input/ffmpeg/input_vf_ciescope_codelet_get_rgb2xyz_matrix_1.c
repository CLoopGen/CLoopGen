#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double m[3][3];
double X[4];
double Z[4];
int i;

void init_vars() {
    for (int j = 0; j < 4; j++) {
        X[j] = (double)(j + 1) * 1.1;
        Z[j] = (double)(j + 1) * 2.2;
    }
}