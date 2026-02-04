#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *state;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 256; i++)
    state[i] = i;

}
