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
        temp[i] = magnitude >> (width - i - 1) & 1 ? '1' : '0';
    }
    for (i = 0; i < width; i++) {
        bits[i] = temp[i];
    }
}
