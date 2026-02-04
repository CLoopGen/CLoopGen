#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern size_t max_depth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile size_t buffer[128]; // prevent optimization
    size_t write_index = 0;
    // Consecutive memory write pattern during bit shifting process
    for (max_depth = 0; i != 0; max_depth++) {
        buffer[write_index++] = i;
        i >>= 1;
        if (write_index >= 128) break;
    }
    // Ensure compiler doesn't optimize out the writes
    i = (size_t)buffer[write_index % 128];
}
