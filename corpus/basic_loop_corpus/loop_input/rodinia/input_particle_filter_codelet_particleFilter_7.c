#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int Nparticles = 10000000; // ~10M particles for ~0.01 sec runtime
double xe = 0.0;
double ye = 0.0;
int x = 0;
double *weights;
double *arrayX;
double *arrayY;

void init_vars() {
    weights = (double*)calloc(Nparticles, sizeof(double));
    arrayX = (double*)calloc(Nparticles, sizeof(double));
    arrayY = (double*)calloc(Nparticles, sizeof(double));

    for (int i = 0; i < Nparticles; i++) {
        weights[i] = (double)(i + 1) / Nparticles;
        arrayX[i] = (double)(i % 1000) + 1.0;
        arrayY[i] = (double)(i % 750) + 1.0;
    }
}