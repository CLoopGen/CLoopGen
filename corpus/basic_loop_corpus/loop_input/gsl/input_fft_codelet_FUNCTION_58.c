#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t k1;
size_t q;

void init_vars() {
    q = 10000000; // Adjusted to achieve approximately 0.01 seconds of loop execution
}