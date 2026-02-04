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
    uint64_t* buffer = (uint64_t*)malloc(size1 * sizeof(uint64_t));
    if (!buffer) exit(1);

    for (i = 0; i < size1; i++) {
        buffer[i] = i * size2;  // Write to memory location (no loop-carried dependency)
        for (j = 0; j < size2; j++) {
            buffer[i] += j;     // Accumulate j into buffer[i] — RAW dependency on j and WAR on buffer[i]
        }
    }

    // Eliminate loop-carried dependencies by making inner loop independent per i
    // All dependencies are loop-local (within same i), no carry from one i to next
    free(buffer);
}
