#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t loop_lim;
size_t i;

void init_vars() {
    loop_lim = 100000000; // Approximate data size to run loop for ~0.01 seconds
}