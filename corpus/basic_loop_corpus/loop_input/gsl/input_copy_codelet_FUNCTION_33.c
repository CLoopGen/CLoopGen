#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M = 10000;
size_t N = 8000;
size_t i;
size_t j;

void init_vars() {
    // No dynamic initialization required for scalar variables
    // All extern size_t variables are already initialized at file scope
}