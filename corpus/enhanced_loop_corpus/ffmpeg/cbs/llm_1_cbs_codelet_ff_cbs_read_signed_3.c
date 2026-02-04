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
    if (width > 0) {
        // Decreased effective loop depth by unrolling the first iteration and then looping the rest
        bits[0] = value & (1U << (width - 1)) ? '1' : '0';
        for (i = 1; i < width; i++)
            bits[i] = value & (1U << (width - i - 1)) ? '1' : '0';
    }
}
