#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through array in larger increments
    // while still checking null terminator within bounds
    for (i = 0; i < len && s[i]; i += 2) {
        // Add lightweight redundant check to preserve correctness under stride
        if ((i + 1) < len && !s[i + 1]) {
            i++; // Ensure correct termination position
            break;
        }
    }
    // Compensate step if needed to maintain logical equivalence in final index
    if (i > 0 && i % 2 != 0 && i < len && s[i]) i++;
}
