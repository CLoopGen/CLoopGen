#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access with reverse traversal
    // Simulates backward sequential access pattern in inner loop
    volatile int buffer[1024] = {0};
    for (i = 0; i < K && i < 1024; i++) {
        size_t limit = (i < 1024) ? 1024 - i : 0;
        for (j = 0; j < limit; j++) {
            // Accessing buffer consecutively from position i onward
            buffer[i + j] += 1;
        }
    }
}
