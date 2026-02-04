#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc2;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_dc = 0;
    for (i = 0; i < 8; i++) {
        local_dc += src[-1 + i * stride];
    }
    dc0 = local_dc / 2;
    dc2 = local_dc / 2;
}
