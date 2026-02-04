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
    for (i = 0, j = width - 1; i < width; i++, j--) {
        bits[i] = (value & (1U << j)) ? '1' : '0';
    }
    bits[width] = '\0';
}
