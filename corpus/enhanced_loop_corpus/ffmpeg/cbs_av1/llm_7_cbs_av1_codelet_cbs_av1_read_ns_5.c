#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t v;
extern int w;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < w - 1; i++) {
        uint32_t shifted = v >> (w - 2 - i);
        bits[i] = (shifted & 1) ? '1' : '0';
    }
}
