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
    src_x = (srcp[i]) << 1;
    dstp[i] = ((1 + src_x + (srcp_above[i]) + (srcp_below[i])) >> 2);
}

}
