#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float MPA_INT;

MPA_INT *window;
int i;
int j;

void init_vars() {
    const size_t total_size = 16 * 1024 * 1024; // 16 MB to ensure ~0.01s runtime
    window = (MPA_INT*)aligned_alloc(32, total_size * sizeof(MPA_INT));
    
    if (!window) {
        exit(1);
    }
    
    // Initialize array with dummy values to avoid undefined behavior
    for (size_t idx = 0; idx < total_size; idx++) {
        window[idx] = (MPA_INT)(idx % 1000) / 100.0f;
    }
}

// Ensure definitions are available at file scope
MPA_INT *window;
int i;
int j;