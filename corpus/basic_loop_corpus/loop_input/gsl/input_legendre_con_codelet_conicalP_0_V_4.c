#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double t = 1.0001;
double f = 0.9999;
double T[8] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
double H[8] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
int i;

void init_vars() {
    t = 1.0001;
    f = 0.9999;
    for (int j = 0; j < 8; j++) {
        T[j] = (j == 0) ? 1.0 : 0.0;
        H[j] = (j == 0) ? 1.0 : 0.0;
    }
    i = 0;
}