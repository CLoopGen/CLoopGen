#include <stdio.h>

#include <inttypes.h>

extern uint32_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        p[i] = (uint8_t)(w >> (8 * i));
        p[i + 2] = (uint8_t)(w >> (8 * (i + 2)));
    }
}
