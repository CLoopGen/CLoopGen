#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int h;
extern int depth;
extern uint16_t *dsty;
extern int16_t *srcy;
extern ptrdiff_t stridey;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t max_val = (1LL << depth) - 1;
    int64_t scaled_max_sq = max_val * max_val;
    for (j = 0; j < h; j++) {
        int64_t temp_accum = 0;
        for (i = 0; i < w; i++) {
            int16_t current_src = srcy[i];
            int64_t square = (int64_t)current_src * current_src;
            temp_accum += square; // Introduce artificial accumulation (WAW dependency on temp_accum)
            if (current_src <= 0)
                dsty[i] = 0;
            else if (current_src > max_val)
                dsty[i] = 65535;
            else {
                int64_t intermediate = square * 65535;
                dsty[i] = (uint16_t)(intermediate / scaled_max_sq);
            }
        }
        // Use temp_accum to avoid being optimized out (loop-carried dependency introduced via side effect)
        if (temp_accum < 0) { // Dummy condition, logically unreachable but preserves data use
            dsty[0] = 0;
        }
        dsty += stridey;
        srcy += stridey;
    }
}
