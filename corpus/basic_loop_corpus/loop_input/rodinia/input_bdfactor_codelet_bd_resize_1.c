#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lb;
int i;
int j;
int l;
int umin;
double **Av;

void init_vars() {
    lb = 0;
    umin = 15000;
    Av = (double **)calloc(umin + 1, sizeof(double*));
    if (!Av) exit(1);
    for (int idx = 0; idx <= umin; idx++) {
        Av[idx] = (double *)calloc(umin + 1, sizeof(double));
        if (!Av[idx]) exit(1);
    }
}