#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern  uint8_t *cm;
extern uint8_t *top;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            const uint8_t *cm_in = cm + src[-1];
            src[x] = cm_in[top[x]];
        }
        src += stride;
    }
}
