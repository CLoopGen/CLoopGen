#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t M = 131072;
size_t N = 131072;
size_t i;

void init_vars() {
    // Ensure data size leads to non-trivial loop execution
    // Using ~131k iterations to target ~0.01 sec on modern CPUs
    M = 131072;
    N = 131072;
}