#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int mx;
extern uint16_t *tmp_ptr;
extern  uint16_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (x = w - 1; x >= 0; x--) {
        if (x + 1 < w) {
            tmp_ptr[x] = (src[x] + ((mx * (src[x + 1] - src[x]) + 8) >> 4));
        } else {
            // Handle boundary: no next element, use src[x] itself to avoid out-of-bounds
            tmp_ptr[x] = src[x];
        }
    }
}
