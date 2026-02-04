#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint64_t *stats;
extern int stats_size;
extern int skip0;
extern uint16_t *map;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access using an index remapping array (simulated via reversed traversal)
    // Simulate indirect access by processing elements in reverse order (reverse indexing)
    for (i = stats_size - 1; i >= 0; i--) {
        int idx = i; // Logical index remains i, but accessed in reverse physical order
        dst[idx] = 255;
        if (stats[idx] || !skip0)
            map[size++] = idx;
    }
}
