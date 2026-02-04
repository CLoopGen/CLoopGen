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
    ptrdiff_t j;
    for (j = 0; j < width; j++) {
        int temp_above = srcp_above[j];
        int temp_below = srcp_below[j];
        int temp_src = srcp[j];
        dstp[j] = ((1 + (temp_src << 1) + temp_above + temp_below) >> 2);
    }
}
