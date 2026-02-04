#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t v;
extern int zeroes;
extern char bits[65];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (zeroes > 0) {
        for (j = 0; j < zeroes; j++) {
            char bit = (v >> (zeroes - j - 1) & 1) ? '1' : '0';
            bits[i++] = bit;
        }
    }
}
