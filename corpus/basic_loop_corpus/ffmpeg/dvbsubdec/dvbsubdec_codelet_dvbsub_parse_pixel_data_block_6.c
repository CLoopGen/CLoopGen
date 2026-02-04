#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int i;
extern uint8_t map2to8[];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 4; i++)
    map2to8[i] = *buf++;

}
