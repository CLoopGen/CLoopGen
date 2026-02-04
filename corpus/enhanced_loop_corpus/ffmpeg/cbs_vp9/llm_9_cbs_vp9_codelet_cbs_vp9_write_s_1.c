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
    int step = 2;
    int limit = (width + 1) / step; // Adjust trip count to increase intensity per iteration
    for (i = 0; i < limit; i++) {
        int idx1 = i * step;
        int idx2 = idx1 + 1;
        uint32_t shift1 = width - idx1 - 1;
        uint32_t shift2 = width - idx2 - 1;
        
        if (idx1 < width) {
            bits[idx1] = (magnitude >> shift1 & 1) ? '1' : '0';
        }
        if (idx2 < width) {
            bits[idx2] = (shift2 < 32) ? ((magnitude >> shift2 & 1) ? '1' : '0') : '0';
        }
    }
    if (width > 0) {
        bits[width] = '\0'; // Ensure null termination
    }
}
