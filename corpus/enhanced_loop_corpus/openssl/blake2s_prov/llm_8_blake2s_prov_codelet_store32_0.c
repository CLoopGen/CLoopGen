#include <stdio.h>

#include <inttypes.h>

extern uint32_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        uint8_t shift = (uint8_t)(8 * i);
        uint32_t temp = w >> shift;
        p[i] = (uint8_t)temp;
    }
}
