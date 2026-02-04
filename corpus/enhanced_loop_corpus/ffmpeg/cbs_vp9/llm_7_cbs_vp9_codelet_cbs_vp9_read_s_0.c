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
    int j = width - 1;
    for (i = 0; i < width; i++) {
        bits[j - i] = magnitude >> i & 1 ? '1' : '0';
    }
}
