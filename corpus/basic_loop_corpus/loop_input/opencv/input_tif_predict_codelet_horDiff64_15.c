#include <stdlib.h>
#include <stddef.h>

typedef int tmsize_t;

tmsize_t stride;
tmsize_t i;

void init_vars() {
    stride = 1000000; // Ensures loop runs approximately 1e6 iterations, which is in the desired time range
}