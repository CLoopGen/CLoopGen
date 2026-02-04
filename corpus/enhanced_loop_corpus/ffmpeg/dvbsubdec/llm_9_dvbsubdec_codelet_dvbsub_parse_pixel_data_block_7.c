#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int i;
extern uint8_t map4to8[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i++) {
        uint8_t val = (i % 2 == 0) ? (*buf >> 4) : (*buf & 0x0F);
        map4to8[i / 2] |= val << ((i % 2) * 4);
        if (i % 2 == 1) buf++;
    }
}
