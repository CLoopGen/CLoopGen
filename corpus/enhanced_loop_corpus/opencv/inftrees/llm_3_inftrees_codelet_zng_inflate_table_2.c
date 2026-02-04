#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int max;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive backward traversal with temporary pointer arithmetic
    uint16_t *ptr = count + max;  // Start at effective end of relevant region
    for (max = 15; max >= 1; max--) {
        ptr--;  // Move pointer backward consecutively
        if (*ptr != 0)
            break;
    }
}
