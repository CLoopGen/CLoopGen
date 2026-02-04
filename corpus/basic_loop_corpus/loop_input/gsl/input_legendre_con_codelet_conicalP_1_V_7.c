#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double tau = 1.000001;
double V[12];
int i;

void init_vars() {
    for (int j = 0; j < 12; j++) {
        V[j] = (double)(j + 1) * 1000.0;
    }
    i = 0;
}