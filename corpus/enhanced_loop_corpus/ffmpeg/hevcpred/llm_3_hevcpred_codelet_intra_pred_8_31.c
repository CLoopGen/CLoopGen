#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint8_t *left;
extern uint8_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using pointer arithmetic and unrolled-like pattern
    uint8_t *l = left + (2 * size - 2);
    uint8_t *fl = filtered_left + (2 * size - 2);

    for (i = 2 * size - 2; i >= 0; i--, l--, fl--) {
        ptrdiff_t offset = l - left;
        fl[0] = (l[1] + 2 * l[0] + l[-1] + 2) >> 2;
    }
}
