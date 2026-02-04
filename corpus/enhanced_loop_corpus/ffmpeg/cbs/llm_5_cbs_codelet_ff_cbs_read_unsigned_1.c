#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t value;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i++) {
        bits[i] = '0';
        if (((value >> (width - i - 1)) & 1) != 0) {
            bits[i] = '1';
            continue;
        }
    }
}
