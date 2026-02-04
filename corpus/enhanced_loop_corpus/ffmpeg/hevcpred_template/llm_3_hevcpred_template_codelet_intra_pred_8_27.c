#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with reversed indexing via pointer arithmetic
    // Instead of iterating backward on index, traverse forward using reversed pointer view
    uint8_t* rev_top = top + (2 * size - 2);
    uint8_t* rev_filtered = filtered_top + (2 * size - 2);

    // Traverse forward through the reversed array layout
    for (i = 0; i <= 2 * size - 2; i++) {
        // Access neighbors in original order: [i+1], [i], [i-1] become [-1], [0], [+1] in reversed frame
        // So at current rev_top[0], we need rev_top[-1] (future), rev_top[0], rev_top[1] (past)
        filtered_top[2 * size - 2 - i] = (rev_top[-1] + 2 * rev_top[0] + rev_top[1] + 2) >> 2;

        // Move pointer backward in original array to simulate forward scan in reversed index space
        rev_top--;
        rev_filtered--;
    }
}
