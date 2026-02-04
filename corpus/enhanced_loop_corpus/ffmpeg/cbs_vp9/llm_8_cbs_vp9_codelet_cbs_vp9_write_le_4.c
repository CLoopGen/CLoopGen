#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t value;
extern int b;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (b = 0; b < width; b += 4)
        for (i = 0; i < 4; i++) {
            int index = b + i;
            bits[index] = ((value >> index) & 1) ? '1' : '0';
        }
}
