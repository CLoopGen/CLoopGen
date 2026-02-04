#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t Kevents = 16777216; // ~128 MB of double data (16M elements)

double *ProbArray;
size_t k;
double *E;
double pTotal = 1.0;

void init_vars() {
    ProbArray = (double*)aligned_alloc(32, Kevents * sizeof(double));
    E = (double*)aligned_alloc(32, Kevents * sizeof(double));

    for (size_t i = 0; i < Kevents; ++i) {
        ProbArray[i] = (double)(i + 1);
    }

    pTotal = 1234567.89;
}