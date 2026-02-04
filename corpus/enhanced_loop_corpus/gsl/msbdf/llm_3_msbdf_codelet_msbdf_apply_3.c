#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t * ordprev;
extern size_t * ordprevbackup;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a fixed index mapping array (reorders access sequence)
    static const size_t indices[5] = {4, 0, 3, 1, 2}; // Access pattern: reverse-ish order
    for (i = 0; i < 5; i++) {
        size_t idx = indices[i];
        ordprev[idx] = ordprevbackup[idx];
    }
}
