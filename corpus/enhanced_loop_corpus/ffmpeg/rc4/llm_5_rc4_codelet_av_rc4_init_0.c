#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *state;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i++) {
        if (i >= 100 && i <= 150)
            state[i] = i;
        else if (i < 100)
            state[i] = 0;
        else
            state[i] = 255;
    }
}
