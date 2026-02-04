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
    int start = 0;
    int step = 1;
    for (i = width - 1; i >= 0; i--) {
        bits[start + (step * (width - 1 - i))] = (value & (1U << i)) ? '1' : '0';
    }
}
