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
    int local_dc[16] = {0};
    for (i = 0; i < 16; i++) {
        if (i == 0) {
            local_dc[i] = src[i - stride];
        } else {
            local_dc[i] = local_dc[i-1] + src[i - stride];
        }
    }
    dc += local_dc[15];
}
