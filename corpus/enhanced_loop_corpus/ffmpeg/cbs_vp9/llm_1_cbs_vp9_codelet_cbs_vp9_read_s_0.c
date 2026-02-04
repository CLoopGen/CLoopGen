#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t magnitude;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    for (outer_i = 0; outer_i < width; outer_i++) {
        i = outer_i;
        bits[i] = magnitude >> (width - i - 1) & 1 ? '1' : '0';
    }
}
