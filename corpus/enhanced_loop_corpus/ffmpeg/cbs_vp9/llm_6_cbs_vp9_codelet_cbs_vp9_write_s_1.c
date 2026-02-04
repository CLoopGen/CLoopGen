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
    char temp[33];
    for (i = 0; i < width; i++) {
        int shift = width - i - 1;
        uint32_t shifted_val = magnitude >> shift;
        temp[i] = (shifted_val & 1) ? '1' : '0';
    }
    for (i = 0; i < width; i++) {
        bits[i] = temp[i];
    }
}
