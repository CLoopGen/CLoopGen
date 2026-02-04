#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int32_t value;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < width * 2; i += 2) {
        int shift = width - i - 1;
        char bit = ((value >> shift) & 1) ? '1' : '0';
        bits[i / 2] = bit;
    }
}
