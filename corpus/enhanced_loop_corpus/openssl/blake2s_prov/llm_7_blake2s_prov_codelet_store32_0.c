#include <stdio.h>

#include <inttypes.h>

extern uint32_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 3; i >= 0; i--)
        p[3 - i] = (uint8_t)(w >> (8 * i));
}
