#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t * ordprev;
extern size_t * ordprevbackup;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    size_t indices[5] = {4, 3, 2, 1, 0}; // Reverse order access
    for (i = 0; i < 5; i++) {
        size_t idx = indices[i];
        ordprevbackup[idx] = ordprev[idx];
    }
}
