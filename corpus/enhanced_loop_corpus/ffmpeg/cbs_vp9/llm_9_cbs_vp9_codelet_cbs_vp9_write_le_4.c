#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t value;
extern int b;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (b = 0; b < width; b += 16) {
        int limit = (b + 16 <= width) ? b + 16 : width;
        for (i = b; i < limit; i++)
            bits[i] = (value >> i & 1) ? '1' : '0';
    }
}
