#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int i;
extern uint8_t map4to8[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 15; i >= 0; i--)
        map4to8[15 - i] = buf[i];
}
