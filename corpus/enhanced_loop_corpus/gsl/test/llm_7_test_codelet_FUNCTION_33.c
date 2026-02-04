#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t data[1027];
    for (i = 0; i < 1027; i++) {
        if (i == 0) {
            data[i] = 1;
        } else {
            data[i] = data[i-1] + i; // Create loop-carried RAW (read-after-write) dependency
        }
    }
    // Ensure side effect to prevent elimination
    i = (size_t)(data[1026] % UINTPTR_MAX);
}
