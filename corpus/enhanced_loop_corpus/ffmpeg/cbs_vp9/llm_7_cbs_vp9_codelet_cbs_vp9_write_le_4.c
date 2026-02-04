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
        uint32_t temp_val[8];
        // Precompute shifted values to eliminate repeated shifting of 'value' (introduces WAW and RAW via temp array)
        for (i = 0; i < 8; i++) {
            temp_val[i] = value >> (b + i);
        }
        for (i = 0; i < 8; i++) {
            bits[b + i] = (temp_val[i] & 1) ? '1' : '0';
        }
    }
}
