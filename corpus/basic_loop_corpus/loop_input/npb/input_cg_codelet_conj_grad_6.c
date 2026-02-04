#include <stdio.h>

int firstcol = 0;
int lastcol = 1000000;
double r[1000001]; // Size to accommodate index up to lastcol - firstcol + 1 (j <= lastcol - firstcol + 1)
double rho = 0.0;
int j = 0;

void init_vars() {
    for (int i = 1; i <= 1000000; i++) {
        r[i] = 1.0;
    }
}