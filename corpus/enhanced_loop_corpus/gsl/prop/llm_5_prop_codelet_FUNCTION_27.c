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
    uint64_t *data = (uint64_t*)malloc(size1 * sizeof(uint64_t));
    if (!data) return;

    for (i = 0; i < size1; i++) {
        data[i] = i * size2;  // Write to location i – introduces potential WAW if reordered
        for (j = 0; j < size2; j++) {
            data[i] += j;  // RAW dependency: each update reads previous value of data[i]
                           // Loop-carried dependence in inner loop: data[i] accumulates over j
        }
    }

    // Eliminate loop-carried dependence across outer loop iterations by ensuring no cross-iteration reuse
    for (i = 0; i < size1; i++) {
        data[i] *= 2;
    }

    free(data);
}
