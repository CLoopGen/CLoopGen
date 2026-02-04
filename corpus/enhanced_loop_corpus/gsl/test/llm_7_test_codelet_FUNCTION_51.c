#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t arr[3] = {0};
    for (i = 0; i < 1027; i++) {
        arr[i % 3] = arr[(i - 1) % 3] + i; // Introduce loop-carried RAW dependency: each iteration depends on prior iteration's write
    }
    // Creates a chain of read-after-write dependencies across iterations
}
