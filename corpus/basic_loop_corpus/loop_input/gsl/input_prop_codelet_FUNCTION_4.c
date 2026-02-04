#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Assuming the loop body is empty, we choose sizes to make the loop overhead approximately 0.01 seconds.
    // On a typical modern CPU, an empty double loop like this with two levels of iteration
    // will spend most of its time on loop control. We estimate that about 1e8 iterations total
    // (across both loops) takes roughly 0.01 seconds depending on optimization.

    // Choose size1 and size2 such that their product is around 100 million.
    // Use 10000 x 10000 = 100,000,000.
    size1 = 10000;
    size2 = 10000;
}