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
    int j;
    for (i = 0; i < width; i++) {
        uint8_t sum = srcp[i];
        for (j = 0; j < 3; j++) {
            sum += (j == 0) ? srcp_above[i] : (j == 1) ? srcp_below[i] : srcp[i];
        }
        dstp[i] = (1 + sum) >> 2;
    }
}
