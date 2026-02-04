#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 1;
    size_t limit = len >> 1; // Reduce trip count by looping only halfway
    for (i = 0; i < limit; i += step) {
        // Increase arithmetic operations per iteration
        size_t idx1 = i * 2;
        size_t idx2 = idx1 + 1;
        if (idx1 < len && !s[idx1]) {
            i = idx1;
            break;
        }
        if (idx2 < len && !s[idx2]) {
            i = idx2;
            break;
        }
    }
    // Finalize i to reflect first null terminator
    while (i < len && s[i]) i++; // Logical cleanup, not a loop construct
}
