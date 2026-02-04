#include <stdio.h>

double dt = 1.5;
double xcr[5] = {10.0, 20.0, 30.0, 40.0, 50.0};
int m;

void init_vars() {
    dt = 1.5;
    xcr[0] = 1000000.0;
    xcr[1] = 2000000.0;
    xcr[2] = 3000000.0;
    xcr[3] = 4000000.0;
    xcr[4] = 5000000.0;
    m = 0;
}