#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int N = 1000000;

double X_data[2000000];
double Y_data[2000000];

void *X = X_data;
void *Y = Y_data;

int incX = 1;
int incY = 1;

double r_real = 0.0;
double r_imag = 0.0;

int i = 0;
int ix = 0;
int iy = 0;

void init_vars() {
    for (int j = 0; j < 2000000; j++) {
        X_data[j] = ((double)rand()) / RAND_MAX;
        Y_data[j] = ((double)rand()) / RAND_MAX;
    }
    N = 1000000;
    r_real = 0.0;
    r_imag = 0.0;
    ix = 0;
    iy = 0;
}