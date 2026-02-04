#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access with local array traversal
    // Simulating consecutive access using a stack-allocated buffer
    int32_t buffer[1024];
    const size_t effective_K = K % 1024;
    for (i = 0; i < effective_K; i++) {
        buffer[i] = buffer[i] + 1;  // Self-read and write to enforce access
    }
}
