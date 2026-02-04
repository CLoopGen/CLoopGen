#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int Nparticles = 134217728; // ~256MB total (two arrays of double, each 8 bytes per element)
double xe = 1.5;
double ye = 2.5;
int x;

double *arrayX;
double *arrayY;

void init_vars() {
    arrayX = (double*)calloc(Nparticles, sizeof(double));
    arrayY = (double*)calloc(Nparticles, sizeof(double));
    if (!arrayX || !arrayY) {
        exit(1);
    }
}