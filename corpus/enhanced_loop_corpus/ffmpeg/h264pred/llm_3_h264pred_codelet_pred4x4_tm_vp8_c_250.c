#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern  uint8_t *cm;
extern uint8_t *top;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 4; y++) {
        const uint8_t *cm_in = cm + src[-stride];  // Modified access: use strided negative offset instead of -1
        // Change top indexing to indirect access through a fixed index map, simulating non-unit stride or reordered access
        int indices[4] = {3, 1, 2, 0};  // arbitrary reordering to simulate indirect/non-consecutive pattern
        src[0] = cm_in[top[indices[0]]];
        src[1] = cm_in[top[indices[1]]];
        src[2] = cm_in[top[indices[2]]];
        src[3] = cm_in[top[indices[3]]];
        src += stride;
    }
}
