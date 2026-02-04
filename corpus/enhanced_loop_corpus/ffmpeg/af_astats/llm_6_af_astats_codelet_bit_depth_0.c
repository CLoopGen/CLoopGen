#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t mask;
extern unsigned int result;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint64_t temp_mask = mask;
    unsigned int temp_result = result;
    for (; temp_result && !(temp_mask & 1); --temp_result, temp_mask >>= 1) {
        result = temp_result; // WAW dependency introduced: write-after-write on 'result'
        mask = temp_mask;     // Update shared state only at iteration end
    }
}
