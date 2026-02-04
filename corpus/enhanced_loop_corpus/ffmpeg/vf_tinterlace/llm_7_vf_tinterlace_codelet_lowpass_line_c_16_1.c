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
    if (width > 0) {
        dstp[0] = ((1 + (srcp[0] << 1) + srcp_above[0] + srcp_below[0]) >> 2);
        for (i = 1; i < width; i++) {
            dstp[i] = ((1 + (srcp[i] << 1) + srcp_above[i] + srcp_below[i]) >> 2) ^ dstp[i-1];
        }
    }
}
