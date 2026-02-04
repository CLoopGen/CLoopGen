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
    for (i = 0; i < width && i < 32; i++) {
        int shift = width - i - 1;
        bits[i] = (value >> shift) & 1U ? '1' : '0';
    }
    if (width <= 32)
        bits[width] = '\0';
}
