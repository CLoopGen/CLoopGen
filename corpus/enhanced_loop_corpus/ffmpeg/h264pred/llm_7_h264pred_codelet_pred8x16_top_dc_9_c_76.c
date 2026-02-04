#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_dc = 0;
    for (i = 0; i < 4; i++) {
        local_dc += src[i - stride] + src[4 + i - stride];
    }
    dc0 += local_dc / 2;
    dc1 += local_dc / 2;
}
