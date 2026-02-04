#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

size_t M;
size_t N;
size_t tda;
size_t i;
size_t j;

void init_vars() {
    // Aim for approximately 100 million iterations to target ~0.01 sec runtime on modern CPUs
    // Each iteration does simple arithmetic; adjust problem size accordingly

    // Set M and N such that M * N is about 100e6
    M = 10000;
    N = 10000;
    tda = N;  // tda likely acts as leading dimension, set to N or larger; use N here for safety
}