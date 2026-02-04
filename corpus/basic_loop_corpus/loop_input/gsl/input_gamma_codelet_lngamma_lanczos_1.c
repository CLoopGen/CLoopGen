#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double lanczos_7_c[9];
double x;
int k;
double Ag;

void init_vars() {
    lanczos_7_c[0] = 1.0;
    for (int i = 1; i <= 8; i++) {
        lanczos_7_c[i] = (double)(i * i);
    }
    x = 1.5;
    k = 0;
    Ag = 0.0;
}