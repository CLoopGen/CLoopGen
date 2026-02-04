#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t arr[3] = {0};
    for (i = 0; i < 1027; i++) {
        arr[i % 3] = arr[(i + 2) % 3] + i; // Create loop-carried RAW dependency: each iteration depends on prior writes
    }
    // Introduces RAW (read after write) and WAW dependencies across iterations with modulo indexing
}
