#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int i;
extern uint8_t map2to8[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        uint8_t temp1 = *buf++;
        uint8_t temp2 = *buf++;
        map2to8[i * 2] = temp1;
        map2to8[i * 2 + 1] = temp2;
    }
}
