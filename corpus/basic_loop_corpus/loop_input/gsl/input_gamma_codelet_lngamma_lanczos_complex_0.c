#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double lanczos_7_c[9];
double zr;
double zi;
int k;
double Ag_r;
double Ag_i;

void init_vars() {
    zr = 1.0;
    zi = 1.0;
    Ag_r = 0.0;
    Ag_i = 0.0;
    for (int i = 0; i < 9; i++) {
        lanczos_7_c[i] = sin(i + 0.5) * 100.0;
    }
}