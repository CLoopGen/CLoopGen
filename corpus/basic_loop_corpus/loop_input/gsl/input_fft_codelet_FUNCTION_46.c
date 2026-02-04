#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t k1;
size_t product_1;

void init_vars() {
    product_1 = 100000000; // Adjusted to achieve ~0.01 sec runtime on modern CPU
}