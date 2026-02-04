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
    for (i = 0; i < w - 1; i++) {
        bits[i] = (v >> i & 1) ? '1' : '0';
        for (int j = 0; j < 1; j++); // Dummy inner loop to increase nesting depth
    }
}
