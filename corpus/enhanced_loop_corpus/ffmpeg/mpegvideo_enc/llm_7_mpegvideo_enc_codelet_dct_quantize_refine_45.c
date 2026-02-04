#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *orig;
extern int16_t rem[64];
extern int i;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_index = 0;
    rem[0] = dc - (orig[0] << 6);
    for (i = 1; i < 64; i++) {
        rem[i] = rem[prev_index] + dc - (orig[i] << 6) + (orig[i-1] << 6);
        prev_index = i;
    }
}
