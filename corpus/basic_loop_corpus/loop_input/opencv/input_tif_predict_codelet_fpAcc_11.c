#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int tmsize_t;

tmsize_t stride = 1000000;
tmsize_t i;

void init_vars() {
    // No additional initialization needed for scalar variables
    // stride is already initialized to ensure loop runs ~1e6 iterations
    // which approximates 0.01 seconds on modern CPUs
}