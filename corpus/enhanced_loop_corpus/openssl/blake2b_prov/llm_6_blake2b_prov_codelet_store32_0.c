#include <stdio.h>

#include <inttypes.h>

extern uint32_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp = w;
    for (i = 0; i < 4; i++) {
        p[i] = (uint8_t)(temp & 0xFF);
        temp >>= 8;
    }
}
