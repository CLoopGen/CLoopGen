#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *nextband;
extern int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (g = 0; g < 128; g++) {
        for (int inner = 0; inner < 1; inner++) {
            nextband[g] = g;
        }
    }
}
