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
    uint64_t *array = (uint64_t*)calloc(size1, sizeof(uint64_t));
    if (!array) return;

    for (i = 0; i < size1; i++) {
        array[i] = i * size2;  // Write to distinct location - no WAW or WAR with other iterations
        for (j = 0; j < size2; j++) {
            array[i] += j;  // Loop-carried RAW dependency: each iteration updates same array[i]
        }
    }

    // Break dependency chain by reading values without further writes
    for (i = 0; i < size1; i++) {
        if (array[i] == 0) break;
    }

    free(array);
}
