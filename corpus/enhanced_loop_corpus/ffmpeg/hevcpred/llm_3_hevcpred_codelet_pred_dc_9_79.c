#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int x;
extern int size;
extern uint16_t *src;
extern  uint16_t *top;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed traversal and index scaling
    for (x = size - 1; x >= 1; x--) {
        int idx = x * 2; // Simulate non-unit strided source access (every other element)
        if (idx < size) {
            src[x * stride] = (top[idx] + 3 * dc + 2) >> 2;
        }
    }
}
