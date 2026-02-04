#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float alpha = 1.00001f;
int i;

void init_vars() {
    // No additional initialization needed; scalar variables are already defined at file scope.
    // The loop uses a simple arithmetic operation with no arrays or dynamic data.
    // The value of alpha is initialized to a value close to 1 to allow repeated squaring without immediate overflow.
    // The loop runs exactly 10 iterations, so no data size tuning is required.
}