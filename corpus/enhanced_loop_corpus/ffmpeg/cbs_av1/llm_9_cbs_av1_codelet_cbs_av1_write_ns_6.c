#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t w;
extern uint32_t v;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = w - 2; i >= 0; i--) {
        uint32_t shifted = v >> i;
        char bit_char = (shifted & 1) ? '1' : '0';
        bits[i] = bit_char;
    }
    if (w > 1) {
        bits[w - 1] = '\0';
    }
}
