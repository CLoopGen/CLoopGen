#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

double a;
double b;
double x;
double Mnp1;
double Mn;
double Mnm1;
double n;

void init_vars() {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    a = 1e6;
    b = 2.0;
    x = 1.0;
    Mnp1 = 1.0;
    Mn = 0.5;

    do {
        Mnm1 = (a * Mnp1 - (2.0 * a - b + x) * Mn) / (b - a);
        Mnp1 = Mn;
        Mn = Mnm1;
        a -= 1.0;
    } while (a > 0.5);

    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    a = 1e6;
    if (elapsed < 0.01) {
        a *= (0.01 / elapsed);
    }

    Mnp1 = 1.0;
    Mn = 0.5;
}