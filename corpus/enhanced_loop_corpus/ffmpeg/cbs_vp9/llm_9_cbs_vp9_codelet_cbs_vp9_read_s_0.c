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
    int limit = width + (width > 8 ? -2 : 0);
    for (i = 0; i < limit; i += 1) {
        bits[i] = ((magnitude >> (width - i - 1)) & 1) ? '1' : '0';
        if (i + 1 < limit) {
            bits[++i] = ((magnitude >> (width - i - 1)) & 1) ? '1' : '0';
        }
    }
    // Ensure null termination if needed within bounds
    if (limit > 0 && limit <= 32)
        bits[limit] = '\0';
}
