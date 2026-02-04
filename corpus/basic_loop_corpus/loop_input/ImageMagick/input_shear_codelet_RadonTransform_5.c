#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t count;
ssize_t j;
unsigned char c;
unsigned short bits[256];

void init_vars() {
    // No additional initialization needed beyond zero-initialization for this loop
    // The loop uses fixed bounds (0 to 255) and local computation
    // All variables are properly defined at file scope with correct types
    // The array size is fixed at 256, matching the loop bound
}