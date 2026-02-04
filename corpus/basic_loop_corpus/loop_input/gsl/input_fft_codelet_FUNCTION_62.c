#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t k1;
size_t m = 1024;
size_t q = 10000;
size_t product_1 = 1024;

void init_vars() {
    // Ensure that memory accesses in the loop stay within bounds
    // The maximum index used is from1 = (q - 1) * product_1 + product_1 - 1 + m
    // which simplifies to: q * product_1 - 1 + m
    // With current values: q=10000, product_1=1024, m=1024 -> ~10MB total span
    // This should provide sufficient data size for ~0.01 sec runtime on modern CPU

    // No dynamic arrays are directly accessed in the loop,
    // but boundary parameters are set conservatively to avoid overflow.
}