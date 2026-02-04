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
    // Variant 2: Consecutive access using pointer arithmetic and offset indexing
    uint16_t *l = left + (2 * size - 2);
    uint16_t *fl = filtered_left + (2 * size - 2);

    for (i = 2 * size - 2; i >= 0; i--) {
        fl[0] = (l[1] + 2 * l[0] + l[-1] + 2) >> 2;
        l--;
        fl--;
    }
}
