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
    int j, i;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++) {
            ((uint32_t *)(src + i * stride))[0] = ((uint32_t *)(src + i * stride))[1] = dc0;
        }
    }
}
