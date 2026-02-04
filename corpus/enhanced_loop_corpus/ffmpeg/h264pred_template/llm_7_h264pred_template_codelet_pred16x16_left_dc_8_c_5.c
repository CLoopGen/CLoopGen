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
    int local_dc[16];
    for (i = 0; i < 16; i++) {
        local_dc[i] = (i == 0) ? src[-1] : local_dc[i-1] + src[-1 + i * stride];
    }
    dc += local_dc[15];
}
