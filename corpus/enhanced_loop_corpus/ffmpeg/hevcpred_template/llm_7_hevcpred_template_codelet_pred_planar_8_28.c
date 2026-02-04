#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int trafo_size;
extern int x;
extern int y;
extern uint8_t *src;
extern  uint8_t *top;
extern  uint8_t *left;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t s = stride;
    int sz = size;
    int tr_shift = trafo_size + 1;
    uint8_t *local_src = src;
    uint8_t *local_top = top;
    uint8_t *local_left = left;

    // Introduce loop-carried dependence in x-direction by making current x dependent on previous x
    for (y = 0; y < sz; y++) {
        int prev_val = 0; // Carry value from previous iteration (x-1)
        for (x = 0; x < sz; x++) {
            int base_index = x + s * y;
            int raw_term = ((sz - 1 - x) * local_left[y] + 
                           (x + 1) * local_top[sz] + 
                           (sz - 1 - y) * local_top[x] + 
                           (y + 1) * local_left[sz] + 
                           sz + prev_val) >> tr_shift;

            local_src[base_index] = (uint8_t)(raw_term & 0xFF);
            prev_val = raw_term << tr_shift; // WAW-like feedback creates RAW dependence across iterations
        }
    }
}
