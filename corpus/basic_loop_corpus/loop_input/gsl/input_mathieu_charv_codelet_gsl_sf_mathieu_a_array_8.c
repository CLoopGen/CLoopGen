#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double qq = 3.141592653589793;
unsigned int even_order;
unsigned int ii;
double *tt;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB of data
    even_order = (data_size / sizeof(double)) / 3;
    if (even_order % 2 != 0) even_order--;

    tt = aligned_alloc(32, data_size);
    if (!tt) {
        exit(1);
    }
}