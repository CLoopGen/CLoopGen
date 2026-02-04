#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M = 1024;
size_t N = 1024;
size_t tda = 1024;
size_t i;
size_t j;

void init_vars() {
    // Ensure data size is around 1MB - 256MB: here we use M*N*sizeof(size_t) ~ 1MB for 1024x1024
    // No dynamic allocation needed as loop only computes index 'k'
    // All required variables are already defined at file scope with appropriate sizes
}