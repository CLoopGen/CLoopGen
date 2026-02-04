#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_dc0 = dc0;
    int temp_dc1 = dc1;
    for (i = 0; i < 4; i++) {
        temp_dc0 += src[i - stride];
        temp_dc1 += src[4 + i - stride];
    }
    dc0 = temp_dc0;
    dc1 = temp_dc1;
}
