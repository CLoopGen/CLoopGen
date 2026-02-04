#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming typical modern CPU can handle nested loops with ~100M iterations in about 0.01s
    size1 = 10000;  // Outer loop count
    size2 = 10000;  // Inner loop count
}