#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t i;

void init_vars() {
    // No additional initialization needed for scalar loop index
    // Loop bounds (0 to 1026) are safe as i is size_t and loop condition is i < 1027
}