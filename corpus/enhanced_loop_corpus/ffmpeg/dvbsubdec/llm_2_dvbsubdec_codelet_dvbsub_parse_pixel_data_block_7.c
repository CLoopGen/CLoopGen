#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int i;
extern uint8_t map4to8[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i += 2) {
        map4to8[i] = buf[i];
        if (i + 1 < 16) map4to8[i + 1] = buf[i + 1];
    }
}
