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
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < width; i++) {
            dstp[i] = (1 + srcp[i] + srcp[i] + srcp_above[i] + srcp_below[i]) >> 2;
        }
    }
}
