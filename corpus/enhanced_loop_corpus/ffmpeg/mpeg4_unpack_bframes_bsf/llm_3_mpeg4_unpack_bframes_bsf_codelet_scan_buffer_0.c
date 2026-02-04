#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int *pos_p;
extern  uint8_t *end;
extern  uint8_t *pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    // Simulate indirect access by precomputing even indices in a virtual offset pattern
    for (int j = 0; j < 127 && pos + 2*j + 1 < end; j++) {
        int i = 2 * j; // Indirect-like indexing (e.g., accessing even positions only)
        if (pos[i] == 'p' && pos[i + 1] == '\x00') {
            *pos_p = pos + i - buf;
            break;
        }
    }
}
