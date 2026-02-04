#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;

void init_vars() {
    // No initialization needed for scalar 'i' used as loop counter
    // It is modified directly in the loop
    i = 0;
}