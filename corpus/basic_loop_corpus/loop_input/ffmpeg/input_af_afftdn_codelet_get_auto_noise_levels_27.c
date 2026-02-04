#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *levels;

void init_vars() {
    levels = (double *)aligned_alloc(32, 15 * sizeof(double));
    if (!levels) {
        exit(1);
    }
}

__attribute__((destructor))
static void cleanup() {
    free(levels);
}