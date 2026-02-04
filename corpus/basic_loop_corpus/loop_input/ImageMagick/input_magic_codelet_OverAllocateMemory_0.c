#include <stdlib.h>
#include <stdint.h>

size_t length = 1 << 28; // ~256MB to ensure loop runs ~0.01 sec
size_t extent;

void init_vars() {
    // No additional initialization needed for basic scalar variables
    // Values are already set at file scope where necessary
}