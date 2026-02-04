#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern uint8_t *top;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y++) {
        uint8_t prev_val = top[0];
        uint8_t curr_val = top[1];
        uint8_t next_val = top[2];
        for (x = 0; x < 8; x++) {
            uint8_t new_next = (x + 2 < 256) ? top[x + 2] : next_val;
            d[y * stride + x] = ((prev_val + 2 * curr_val + next_val + 2) >> 2);
            prev_val = curr_val;
            curr_val = next_val;
            next_val = new_next;
        }
    }
}
