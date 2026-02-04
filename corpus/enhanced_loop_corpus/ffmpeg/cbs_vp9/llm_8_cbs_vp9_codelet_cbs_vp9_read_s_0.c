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
    int j;
    for (i = 0; i < width; i++) {
        int shift_amount = width - i - 1;
        uint32_t shifted = magnitude >> shift_amount;
        bits[i] = (shifted & 1) ? '1' : '0';
    }
}
