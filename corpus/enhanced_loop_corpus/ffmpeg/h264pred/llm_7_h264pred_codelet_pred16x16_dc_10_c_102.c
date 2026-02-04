#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t local_accum[16];
    for (i = 0; i < 16; i++) {
        local_accum[i] = (i == 0) ? src[-1] : local_accum[i-1] + src[-1 + i * stride];
    }
    dc += local_accum[15];
}
