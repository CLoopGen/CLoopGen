#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int Nparticles;
int x;
double *weights;

void init_vars() {
    Nparticles = 1 << 24;  // 16.7 million particles -> ~134 MB for weights array
    weights = (double*)calloc(Nparticles, sizeof(double));
    if (!weights) {
        exit(1);
    }
}