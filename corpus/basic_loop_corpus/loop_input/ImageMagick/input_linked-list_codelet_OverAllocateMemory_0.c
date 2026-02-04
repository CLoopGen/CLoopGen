#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t length = 1 << 28; // Approximately 256MB to ensure loop runs ~0.01s
size_t extent = 0;

void init_vars() {
    // No additional initialization needed for scalar variables
    // They are already initialized at file scope
}