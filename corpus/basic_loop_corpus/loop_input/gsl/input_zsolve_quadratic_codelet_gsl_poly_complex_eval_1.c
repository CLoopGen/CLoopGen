#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double dat[2];
} gsl_complex;

double c[1 << 20]; // 8MB array of doubles (~1M elements)
int len = 1 << 20;
gsl_complex z;
int i;
gsl_complex ans;

void init_vars() {
    z.dat[0] = 1.0;
    z.dat[1] = 0.5;
    ans.dat[0] = 1.0;
    ans.dat[1] = 0.0;

    for (int j = 0; j < len; j++) {
        c[j] = (double)j * 0.0001;
    }
}