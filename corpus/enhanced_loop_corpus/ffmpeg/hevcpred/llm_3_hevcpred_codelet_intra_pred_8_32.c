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
    // Variant 2: Consecutive forward traversal using pointer arithmetic
    // Original loop is backward; this variant reverses iteration order
    // and uses pointers to create a consecutive forward access pattern.
    uint8_t *t = top + 1;
    uint8_t *ft = filtered_top + 0;
    int limit = 2 * size - 1;

    for (i = 0; i < limit; i++) {
        ft[i] = (t[i] + 2 * t[i - 1] + t[i - 2] + 2) >> 2;
    }
}
