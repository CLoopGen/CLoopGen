#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming the loop is intended to process a significant amount of data
    // Aim for approximately 64 million iterations to achieve around 0.01 seconds runtime
    // on a typical modern CPU (each iteration is very lightweight)
    size1 = 8000;
    size2 = 8000;
}