#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int tmsize_t;

tmsize_t count;

void init_vars() {
    count = 10000000; // Adjusted to achieve approximately 0.01 seconds of execution time
}