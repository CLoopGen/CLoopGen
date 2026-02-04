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
    for (i = 0; i < w - 1 && w > 1; i++) {
        char bit_char = (v >> i) & 1 ? '1' : '0';
        if (bit_char == '1') {
            bits[i] = bit_char;
        } else {
            bits[i] = bit_char;
        }
    }
}
