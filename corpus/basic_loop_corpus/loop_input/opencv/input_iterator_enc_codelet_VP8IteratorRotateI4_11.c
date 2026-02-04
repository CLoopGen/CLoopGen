#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;

void init_vars() {
    // No additional initialization needed for scalar variable 'i'
    // It is declared at file scope and will be zero-initialized by default.
    // The loop uses i as a counter from 0 to 3, which is safe.
}