#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *state;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            state[i * 16 + j] = i * 16 + j;
        }
    }
}
