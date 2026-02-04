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
    for (b = 0; b < width; b += 8) {
        int offset = b;
        for (i = 0; i < 4; i++) {
            bits[offset + i] = (value >> (offset + i)) & 1 ? '1' : '0';
            bits[offset + i + 4] = (value >> (offset + i + 4)) & 1 ? '1' : '0';
        }
    }
}
