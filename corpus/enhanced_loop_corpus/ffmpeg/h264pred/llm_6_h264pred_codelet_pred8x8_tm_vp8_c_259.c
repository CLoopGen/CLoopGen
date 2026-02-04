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
        uint8_t temp[8];
        const uint8_t *cm_in = cm + src[-1];
        for (int i = 0; i < 8; i++) {
            temp[i] = cm_in[top[i]];
        }
        for (int i = 0; i < 8; i++) {
            src[i] = temp[i];
        }
        src += stride;
    }
}
