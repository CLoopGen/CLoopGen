#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming the nested loop is intended for memory processing,
    // set sizes to achieve approximately 0.01 seconds of computation.
    // On a modern CPU, simple loops can iterate ~1e9 times per second.
    // Aim for total iterations around 10 million to stay within 0.01 sec.

    size1 = 3000;
    size2 = 3000;
}