#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

size_t loop_lim;
size_t i;

void init_vars() {
    loop_lim = 10000000; // Adjusted to achieve approximately 0.01 seconds of execution time
}