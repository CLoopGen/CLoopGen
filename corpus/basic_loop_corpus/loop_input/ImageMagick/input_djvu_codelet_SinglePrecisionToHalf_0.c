#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float alpha = 1.00001f;
int i;

void init_vars() {
    // No additional initialization needed; scalar variables are already defined at file scope.
    // The loop uses only scalar computations with no array or pointer access,
    // and runs for a fixed 10 iterations, so no dynamic setup is required.
}