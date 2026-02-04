#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * (1 << 20) / sizeof(double))

double range[ARRAY_SIZE];
size_t n = ARRAY_SIZE - 1;
double xmin = 1.5;
double xmax = 100.5;
size_t i;

void init_vars() {
    // Ensure n is within bounds for the array
    if (n >= ARRAY_SIZE) {
        n = ARRAY_SIZE - 1;
    }
}