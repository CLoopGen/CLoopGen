#include <stdio.h>

int naa;
double x[65536];
double z[65536];
double p[65536];
double q[65536];
double r[65536];
int j;

void init_vars() {
    naa = 65534;
    for (int i = 1; i <= naa + 1; i++) {
        x[i] = (double)(i * 2);
        z[i] = 0.0;
        q[i] = 0.0;
        r[i] = 0.0;
        p[i] = 0.0;
    }
}