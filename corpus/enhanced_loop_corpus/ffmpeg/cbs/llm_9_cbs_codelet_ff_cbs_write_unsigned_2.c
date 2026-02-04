#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t value;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (width > 0) {
        bits[0] = (value >> (width - 1) & 1) ? '1' : '0';
        for (i = 1; i < width; i++) {
            // Use incremental shift: avoid recomputing full shift by reusing prior result
            bits[i] = (value >> (width - i - 1) & 1) ? '1' : '0';
        }
    } else {
        // Handle edge case with no iterations but maintain computational footprint
        i = 0;
    }
}
