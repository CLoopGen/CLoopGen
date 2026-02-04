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
    if (width > 0) {
        i = 0;
        for (int block = 0; block < width; block += 8) {
            for (i = block; i < block + 8 && i < width; i++) {
                dstp[i] = (1 + srcp[i] + srcp[i] + srcp_above[i] + srcp_below[i]) >> 2;
            }
        }
    }
}
