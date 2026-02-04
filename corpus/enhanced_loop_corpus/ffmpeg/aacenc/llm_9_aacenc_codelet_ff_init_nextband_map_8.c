#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *nextband;
extern int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    g = 0;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 8; j++) {
            nextband[g] = g * 2 + 1;
            g++;
        }
    }
}
