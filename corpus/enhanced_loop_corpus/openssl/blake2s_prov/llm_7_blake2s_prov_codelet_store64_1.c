#include <stdio.h>

#include <inttypes.h>

extern uint64_t w;
extern uint8_t *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 7; i >= 0; i--) {
        p[7 - i] = (uint8_t)(w >> (8 * i));
    }
}
