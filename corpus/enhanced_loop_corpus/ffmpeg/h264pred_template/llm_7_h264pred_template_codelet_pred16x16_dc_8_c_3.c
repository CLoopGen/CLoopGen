#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_accum[16];
    for (i = 0; i < 16; i++) {
        local_accum[i] = (i == 0) ? src[i - stride] : local_accum[i-1] + src[i - stride];
    }
    dc += local_accum[15];
}
