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
    unsigned int temp_dc0 = dc0;
    for (i = 0; i < 8; i++) {
        temp_dc0 += src[i - stride];
    }
    dc0 = temp_dc0;
}
