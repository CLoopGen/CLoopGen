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
    for (i = 0; i < width; i += 2) {
        int val1 = srcp[i] << 2;
        int val2 = srcp[i+1] << 2;
        dstp[i]   = ((2 + val1 + srcp_above[i] + srcp_below[i]) >> 3);
        dstp[i+1] = ((2 + val2 + srcp_above[i+1] + srcp_below[i+1]) >> 3);
    }
}
