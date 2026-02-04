#include <stdio.h>

#include <inttypes.h>

extern uint32_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[4];
    for (i = 0; i < 4; i++)
        temp[i] = (uint8_t)(w >> (8 * i));
    for (i = 0; i < 4; i++)
        p[i] = temp[i];
}
