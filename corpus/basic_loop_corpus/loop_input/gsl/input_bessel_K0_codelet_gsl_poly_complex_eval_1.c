#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double dat[2];
} gsl_complex;

double c[1 << 20]; // ~8MB array (1M doubles), adjust for ~0.01s runtime
int len = 1 << 20;
gsl_complex z = {{1.0, 0.5}};
int i;
gsl_complex ans = {{0.0, 0.0}};

void init_vars() {
    for (int j = 0; j < (1 << 20); j++) {
        c[j] = (double)(j % 1000) / 100.0;
    }
    z.dat[0] = 1.0;
    z.dat[1] = 0.5;
    ans.dat[0] = 0.0;
    ans.dat[1] = 0.0;
    len = 1 << 20;
    i = 0;
}