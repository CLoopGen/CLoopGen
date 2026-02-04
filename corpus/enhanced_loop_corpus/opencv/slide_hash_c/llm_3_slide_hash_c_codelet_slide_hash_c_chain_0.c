#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint16_t Pos;

extern uint32_t entries;
extern uint16_t wsize;
extern unsigned int i;
extern Pos *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access using an index map (simulated via arithmetic)
    // Use reverse indexing to simulate indirect pattern: access from end toward start
    Pos t = (Pos)wsize;
    for (i = 0; i < entries; i++) {
        uint32_t idx = entries - 1 - i;  // Reverse traversal index
        Pos m = q[idx];
        q[idx] = (Pos)(m >= t ? m - t : 0);
    }
}
