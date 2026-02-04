#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double dat[2];
} gsl_complex;

#define DATA_SIZE_MB 64
#define ELEMENTS_PER_MB (1024 * 1024 / sizeof(gsl_complex))
static const int len_value = DATA_SIZE_MB * ELEMENTS_PER_MB;

gsl_complex c[len_value];
int len = len_value;
gsl_complex z = {{1.0, 0.5}};
int i;
gsl_complex ans = {{0.0, 0.0}};

void init_vars() {
    for (int j = 0; j < len; j++) {
        c[j].dat[0] = (double)(j % 100) * 0.01;
        c[j].dat[1] = (double)(j % 75) * 0.02;
    }
    z.dat[0] = 1.0;
    z.dat[1] = 0.5;
    ans.dat[0] = 0.0;
    ans.dat[1] = 0.0;
    i = 0;
}