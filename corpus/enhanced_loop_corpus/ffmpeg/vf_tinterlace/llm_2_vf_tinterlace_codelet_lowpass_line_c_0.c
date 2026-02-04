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
    for (i = 0; i < width; i += 2) {
        dstp[i] = (1 + srcp[i] + srcp[i] + srcp_above[i] + srcp_below[i]) >> 2;
        if (i + 1 < width) {
            dstp[i + 1] = (1 + srcp[i + 1] + srcp[i + 1] + srcp_above[i + 1] + srcp_below[i + 1]) >> 2;
        }
    }
}
