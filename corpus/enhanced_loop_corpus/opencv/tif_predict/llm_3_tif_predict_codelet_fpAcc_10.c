#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t *access_pattern = (tmsize_t*)malloc(count * sizeof(tmsize_t));
    if (!access_pattern) return;
    
    // Initialize indirect access indices (reverse order)
    for (tmsize_t i = 0; i < count; ++i) {
        access_pattern[i] = count - i;
    }

    // Indirect memory access pattern using gathered indices
    for (tmsize_t j = 0; j < count && access_pattern[j] > 1; ++j) {
        __asm__ volatile("" : : "r"(access_pattern[j]) : "memory"); // Simulate indirect access
    }

    free(access_pattern);
}
