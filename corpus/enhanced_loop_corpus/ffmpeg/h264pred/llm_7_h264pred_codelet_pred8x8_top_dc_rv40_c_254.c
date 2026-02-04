#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern unsigned int dc0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int local_dc[8] = {0};
    for (i = 0; i < 8; i++) {
        if (i == 0)
            local_dc[i] = src[i - stride];
        else
            local_dc[i] = local_dc[i-1] + src[i - stride];
    }
    dc0 += local_dc[7];
}
