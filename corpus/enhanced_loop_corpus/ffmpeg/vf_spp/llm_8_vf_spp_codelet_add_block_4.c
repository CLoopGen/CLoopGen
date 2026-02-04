#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern int linesize;
extern  int16_t block[64];
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++) {
    dst[0 + y * linesize] += block[0 + y * 8];
    dst[1 + y * linesize] += block[1 + y * 8];
    dst[2 + y * linesize] += block[2 + y * 8];
    dst[3 + y * linesize] += block[3 + y * 8];
}
}
