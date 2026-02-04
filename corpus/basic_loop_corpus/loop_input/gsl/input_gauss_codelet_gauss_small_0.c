#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int i;
double xsq = 2.5;
double xnum = 1.5;
double xden = 1.0;
double a[5] = { 0.1, 0.2, 0.3, 0.4, 0.5 };
double b[4] = { 0.05, 0.15, 0.25, 0.35 };

void init_vars() {
    xsq = 2.5;
    xnum = 1.5;
    xden = 1.0;
    for (int j = 0; j < 5; j++) {
        if (j < 5) a[j] = (double)(j + 1) * 0.1;
    }
    for (int k = 0; k < 4; k++) {
        if (k < 4) b[k] = (double)(k + 1) * 0.05;
    }
}