#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming the loop is intended to process a significant amount of data
    // Aim for approximately 64 million iterations to take ~0.01 seconds on modern CPU

    size1 = 8000;
    size2 = 8000;
}