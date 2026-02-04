#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t ilow;
size_t ihigh;
double mean;
double k;
size_t i;

void init_vars() {
    ilow = 0;
    ihigh = 10000000;  // Adjusted for ~0.01 sec runtime on modern CPU
    mean = 0.0;
    k = 0.0;
}