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
    for (i = 0; i < w; i += 2) {
        if (i + 1 < w) {
            int i1 = i;
            int i2 = i + 1;
            dstp[i1] = ((1 + (srcp[i1] << 1) + srcp_above[i1] + srcp_below[i1]) >> 2);
            dstp[i2] = ((1 + (srcp[i2] << 1) + srcp_above[i2] + srcp_below[i2]) >> 2);
        } else {
            dstp[i] = ((1 + (srcp[i] << 1) + srcp_above[i] + srcp_below[i]) >> 2);
        }
    }
}
