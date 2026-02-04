#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t width;
extern uint16_t *dstp;
extern  uint16_t *srcp;
extern  uint16_t *srcp_above;
extern  uint16_t *srcp_below;
extern int i;
extern int src_x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t w = width;
    for (i = 0; i < w; i++) {
        ptrdiff_t idx = i * 2; // Strided access with step 2 (conceptually, though arrays are still accessed linearly in practice)
        if (idx < w) {
            int val = srcp[idx] << 1;
            dstp[idx] = ((1 + val + srcp_above[idx] + srcp_below[idx]) >> 2);
        }
    }
}
