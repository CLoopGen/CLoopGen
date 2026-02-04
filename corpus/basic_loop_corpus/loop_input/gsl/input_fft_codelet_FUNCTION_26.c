#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t k1;
size_t q = 1024;
size_t m = 512;
size_t product_1 = 1024;

void init_vars() {
    // Initialize parameters to ensure the loop runs for approximately 0.01 seconds
    // and memory accesses (if any) stay within bounds.
    // Based on typical modern CPU speed, aim for around 1M-256M operations.
    // The loop runs 'product_1' iterations, each involving simple arithmetic.
    // Setting product_1 = 1024, q = 1024, m = 512 gives sufficient computation
    // without actual array accesses going out of bounds, as no arrays are used in the loop.
}