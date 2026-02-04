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
    for (i = 0; i < width; i++) {
        bits[i] = '0';
        for (j = 0; j < 1; j++) {  // Artificially nested single-iteration loop
            if (value & (1U << (width - i - 1)))
                bits[i] = '1';
        }
    }
    bits[width] = '\0';  // Ensure null-termination for string safety
}
