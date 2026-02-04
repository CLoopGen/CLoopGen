#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with pointer arithmetic and reordered computation
    // Rewriting loop to traverse from end to beginning using pointers directly
    uint16_t *fp = filtered_top + 2 * size - 2;
    uint16_t *tp_center = top + 2 * size - 2;
    uint16_t *tp_prev = tp_center - 1;
    uint16_t *tp_next = tp_center + 1;

    for (i = 2 * size - 2; i >= 0; i--, fp--, tp_center--, tp_prev--, tp_next--) {
        *fp = (*tp_next + 2 * *tp_center + *tp_prev + 2) >> 2;
    }
}
