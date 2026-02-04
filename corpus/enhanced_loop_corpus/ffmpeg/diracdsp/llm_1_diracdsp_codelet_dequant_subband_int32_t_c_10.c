#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern  int qf;
extern  int qs;
extern int tot_v;
extern int tot_h;
extern int i;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Flattened single-loop variant: reduce nesting depth by merging two loops into one using linear index arithmetic
    int32_t c;
    int total_elements = tot_v * tot_h;
    int32_t *flat_src = (int32_t *)src;
    uint8_t *current_dst = dst;
    
    for (i = 0; i < total_elements; i++) {
        c = flat_src[i];
        if (c < 0)
            c = -((-(unsigned int)c * qf + qs) >> 2);
        else if (c > 0)
            c = (((unsigned int)c * qf + qs) >> 2);
        
        ((int32_t *)current_dst)[i % tot_h] = c;

        // Update destination pointer at row boundaries
        if ((i + 1) % tot_h == 0) {
            current_dst += stride;
        }
    }
}
