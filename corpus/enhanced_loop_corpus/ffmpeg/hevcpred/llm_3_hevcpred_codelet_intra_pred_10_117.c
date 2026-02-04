#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint16_t *left;
extern uint16_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse access but using pointer arithmetic instead of indexing
    // This modifies memory access to use base pointers with negative offsets
    uint16_t *p_left = left + (2 * size - 1);           // Point to one past last valid element for safe offset
    uint16_t *p_filtered = filtered_left + (2 * size - 2);

    for (i = 2 * size - 2; i >= 0; i--) {
        *(p_filtered--) = (*(p_left + 0) + 2 * *(p_left - 1) + *(p_left - 2) + 2) >> 2;
        p_left--;
    }
}
