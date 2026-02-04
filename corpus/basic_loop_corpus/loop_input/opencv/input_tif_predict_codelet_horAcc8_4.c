#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int tmsize_t;

tmsize_t stride = 1000000;
tmsize_t i;

void init_vars() {
    // Initialize variables if needed; current loop does not require complex setup
    // Adjust stride to ensure loop runs for desired duration
    stride = 1000000; // Approximate to run loop ~1M iterations, which is reasonable for ~0.01 sec on modern CPU
}