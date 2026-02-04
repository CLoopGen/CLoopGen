#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;

void init_vars() {
    // No additional initialization needed for scalar variable 'i'
    // It is declared at file scope and will be default-initialized to 0
    // The loop uses 'i' as a loop counter from 0 to 1, which is safe
}