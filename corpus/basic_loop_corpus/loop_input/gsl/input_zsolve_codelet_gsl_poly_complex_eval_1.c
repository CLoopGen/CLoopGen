#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double dat[2];
} gsl_complex;

double c[1 << 24]; // ~16M doubles, ~128MB
int len = 1 << 24;
gsl_complex z = {.dat = {1.5, 0.5}};
int i;
gsl_complex ans = {.dat = {1.0, 0.0}};

void init_vars() {
    for (int j = 0; j < len; j++) {
        c[j] = (double)(j % 100) / 100.0;
    }
    z.dat[0] = 1.5;
    z.dat[1] = 0.5;
    ans.dat[0] = 1.0;
    ans.dat[1] = 0.0;
    i = 0;
    len = 1 << 24; // Ensure length is set to 16M
}