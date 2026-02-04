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
    for (i = 0; i < width; i++) {
        int sum = srcp[i] + srcp_above[i] + srcp_below[i];
        int weighted = (sum * 3) + srcp_above[i] - srcp_below[i];
        dstp[i] = (weighted >> 3);
    }
}
