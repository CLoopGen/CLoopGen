#include <stdio.h>

double dt = 1.5;
double xcr[5] = {10.0, 20.0, 30.0, 40.0, 50.0};
int m;

void init_vars() {
    dt = 1.5;
    for (int i = 0; i < 5; i++) {
        xcr[i] = (i + 1) * 10.0;
    }
    m = 0;
}