#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < M; i++) {
        unsigned int k = i * 2;
        k += 5;
        // Introduce a RAW (read-after-write) dependency: each use of k depends on its prior definition
        // Also introduces a loop-carried WAW (write-after-write) if compiler tries to reorder, but none semantically
        if (k > 10) {
            k = k / 2;
        }
    }
}
