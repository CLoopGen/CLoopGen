#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated using stride offsets)
    // Instead of direct pointer traversal, use an auxiliary index mapping to simulate indirect access.
    // Here we simulate it with fixed offset jumps to mimic irregular but deterministic access.
    size_t idx;
    size_t indices[256]; // Simulated index map; in practice could be dynamic
    for (idx = 0; idx < 256 && idx * 3 < SIZE_MAX; idx++) {
        indices[idx] = idx * 3; // Generate strided indices (indirect-like access)
    }
    for (idx = 0; indices[idx] < SIZE_MAX && content[indices[idx]] != '\x00'; idx++) {
        p = content + indices[idx];
        length += (*p & 128) != 0 ? 2 : 1;
    }
}
