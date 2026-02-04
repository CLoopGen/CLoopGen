#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double dat[2];
} gsl_complex;

double c[131072]; // ~1MB of data: 131072 * sizeof(double) = 1MB
int len = 131072;
gsl_complex z = {{1.0, 0.5}};
int i;
gsl_complex ans = {{2.0, 1.5}};

void init_vars() {
    for (int j = 0; j < len; j++) {
        c[j] = (double)(j % 100) / 10.0;
    }
    len = 131072; // ensure proper length
    z.dat[0] = 1.0;
    z.dat[1] = 0.5;
    ans.dat[0] = 2.0;
    ans.dat[1] = 1.5;
    i = 0;
}