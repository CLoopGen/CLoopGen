#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t* buffer = (int64_t*)calloc(size2, sizeof(int64_t));
    if (!buffer) return;

    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            buffer[j] = i + j; // WAW: each iteration writes to buffer[j], no loop-carried dep in j-loop
        }
        // Break potential reuse by resetting element 0 based on sum (introduce WAR-like pattern)
        if (i > 0) {
            buffer[0] = buffer[size2/2] + buffer[size2-1]; // RAW: reads after prior writes
        }
    }

    free(buffer);
}
