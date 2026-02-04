#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t i;

void init_vars() {
    // No additional initialization needed for scalar loop index
    // The loop uses only the global size_t variable 'i'
    // Data size is not required since no array is accessed in the loop
    // Loop runs 1027 iterations, which is fixed and safe
}