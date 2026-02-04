#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t data[2] = {1, 1};
    for (i = 0; i < 1027; i++) {
        uint64_t next = data[0] + data[1];
        data[i % 2] = next; // Create loop-carried dependency: each iteration depends on prior writes (RAW)
    }
    // Uses recurrence with alternating indexing to maintain dependency chain
}
