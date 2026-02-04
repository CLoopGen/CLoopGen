#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

unsigned int even_order;
unsigned int ii;
double *zz;

void init_vars() {
    size_t num_doubles = 64 * 1024 * 1024 / sizeof(double); // ~64 MB of data
    even_order = (unsigned int)sqrt((double)num_doubles);
    even_order &= ~1U; // Ensure it's even
    if (even_order == 0) even_order = 2;
    num_doubles = (size_t)even_order * (size_t)even_order;
    zz = (double*)calloc(num_doubles, sizeof(double));
}