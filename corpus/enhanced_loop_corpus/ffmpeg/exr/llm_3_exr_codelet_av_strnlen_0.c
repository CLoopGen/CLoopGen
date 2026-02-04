#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    // Use a synthetic stride table concept with offset pointers
    char *ptr = s;
    size_t idx = 0;
    for (i = 0; i < len; i++) {
        ptr = s + idx; // Simulate indirect access through computed index
        if (idx >= len || !ptr[0]) break;
        idx++; // Linear indirect progression (could be randomized but kept deterministic)
    }
    i = idx; // Final index reflects loop progress
}
