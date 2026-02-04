#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int tmsize_t;

tmsize_t cc;
tmsize_t stride;
tmsize_t i;

void init_vars() {
    // Assuming typical modern CPU can handle ~1e8 operations per second,
    // set problem size so loop runs for approximately 0.01 seconds.
    // Aim for around 1e6 to 1e7 iterations.

    // Use 8 million iterations as a reasonable target for ~0.01s
    cc = 8000000;
    stride = 1;
    i = 0;
}