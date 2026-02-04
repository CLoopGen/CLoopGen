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
    char temp[33] = {0};
    for (i = 0; i < width; i++) {
        int shift = width - i - 1;
        int mask = 1U << shift;
        int bit_val = value & mask;
        temp[i] = bit_val ? '1' : '0';
    }
    for (i = 0; i < width; i++) {
        bits[i] = temp[i];
    }
}
