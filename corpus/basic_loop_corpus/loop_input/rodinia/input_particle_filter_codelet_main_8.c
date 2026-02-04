#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int Nparticles;
int *seed;
int i;

void init_vars() {
    Nparticles = 64 * 1024 * 1024 / sizeof(int);  // ~256MB of data
    seed = (int*)malloc(Nparticles * sizeof(int));
    if (!seed) {
        exit(1);
    }
}