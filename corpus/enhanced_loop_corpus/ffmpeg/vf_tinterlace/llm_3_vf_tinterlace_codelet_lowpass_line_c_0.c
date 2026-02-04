#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dstp;
extern ptrdiff_t width;
extern  uint8_t *srcp;
extern  uint8_t *srcp_above;
extern  uint8_t *srcp_below;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (i = 0; i < width; i++) {
        int idx = (i * stride) % width;
        dstp[idx] = (1 + srcp[idx] + srcp[idx] + srcp_above[idx] + srcp_below[idx]) >> 2;
    }
}
