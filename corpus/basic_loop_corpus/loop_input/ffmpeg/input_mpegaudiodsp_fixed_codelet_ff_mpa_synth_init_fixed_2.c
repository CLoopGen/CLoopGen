#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t MPA_INT;

MPA_INT *window;
int i;
int j;

void init_vars() {
    size_t total_size = 16 * 1024 * 1024; // 16 MB for sufficient runtime (~0.01 sec)
    window = (MPA_INT*)aligned_alloc(64, total_size * sizeof(MPA_INT));
    
    if (!window) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; ++idx) {
        window[idx] = (MPA_INT)(idx & 0x7FFFFFFF);
    }
}

// Ensure definitions are present even without main
static void __attribute__((constructor)) initialize() {
    init_vars();
}