#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double levels[64];
ssize_t i;

void init_vars() {
    // No additional initialization needed beyond static definitions
    // since the array is already initialized to zero by default,
    // but the loop will set each element to 2.0 anyway.
}