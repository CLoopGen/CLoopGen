#include <stdlib.h>
#include <stdint.h>

double b6[] = {0.1, 0.2, 0.3, 0.4, 0.5};
size_t dim = 10000000;
double h = 0.01;
double y[10000000];
size_t i;
double * k1;
double * k2;
double * k3;
double * k4;
double * k5;
double * ytmp;

void init_vars() {
    k1 = (double*)malloc(dim * sizeof(double));
    k2 = (double*)malloc(dim * sizeof(double));
    k3 = (double*)malloc(dim * sizeof(double));
    k4 = (double*)malloc(dim * sizeof(double));
    k5 = (double*)malloc(dim * sizeof(double));
    ytmp = (double*)malloc(dim * sizeof(double));

    for (size_t idx = 0; idx < dim; idx++) {
        y[idx] = (double)(idx % 100) / 10.0;
        k1[idx] = 0.1;
        k2[idx] = 0.2;
        k3[idx] = 0.3;
        k4[idx] = 0.4;
        k5[idx] = 0.5;
    }
}