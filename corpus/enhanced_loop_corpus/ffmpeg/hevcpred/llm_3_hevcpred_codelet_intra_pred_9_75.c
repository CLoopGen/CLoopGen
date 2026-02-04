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
    // Variant 2: Consecutive forward traversal using offset indexing with temporary stride simulation
    int start = 2 * size - 2;
    for (i = 0; i <= start; i++) {
        int idx = start - i; // Reverse the iteration order via index mapping
        filtered_top[idx] = (top[idx + 1] + 2 * top[idx] + top[idx - 1] + 2) >> 2;
    }
}
