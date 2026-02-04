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
    for (b = 0; b < width; b += 8)
        for (i = 0; i < 8; i++) {
            int index = b + i;
            if (index >= width) continue;
            char bit_char = '0';
            if ((value >> index) & 1)
                bit_char = '1';
            bits[index] = bit_char;
        }
}
