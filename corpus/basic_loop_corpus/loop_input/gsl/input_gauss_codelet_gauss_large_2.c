#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
double xsq = 1.5;
double xnum = 0.1;
double xden = 0.2;
double p[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
double q[5] = {0.5, 1.5, 2.5, 3.5, 4.5};

void init_vars() {
    xsq = 1.5;
    xnum = 0.1;
    xden = 0.2;
    for (int j = 0; j < 6; j++) {
        if (j < 5) {
            q[j] = (j + 1) * 0.5;
        }
        p[j] = j + 1;
    }
}