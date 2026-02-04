#include <stdlib.h>
#include <stddef.h>

double *gamma;
ssize_t x;

void init_vars() {
    gamma = (double *)calloc(256, sizeof(double));
}

void loop();