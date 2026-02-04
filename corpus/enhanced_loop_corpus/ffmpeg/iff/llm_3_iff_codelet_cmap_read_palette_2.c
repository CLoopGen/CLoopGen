#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int count;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate random access pattern
    uint32_t *temp_pal = pal;
    for (i = 0; i < count; i++) {
        // Assume indices are just sequential for correctness, but pattern is indirect
        size_t idx = i; // Could be a lookup in an index map, e.g., index_map[i]
        temp_pal[idx] &= 16777215;
    }
}
