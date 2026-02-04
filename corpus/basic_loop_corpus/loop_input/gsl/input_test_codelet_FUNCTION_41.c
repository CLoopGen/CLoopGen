#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t i;

void init_vars() {
    // No dynamic initialization needed for scalar variable i
    // It is a loop counter declared in the loop function
    // All extern variables are already zero-initialized if necessary
}