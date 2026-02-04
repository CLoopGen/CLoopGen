#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t v;
extern int zeroes;
extern char bits[65];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = zeroes + (zeroes >> 1); // Increase trip count by 50%
    for (j = 0; j < limit; j++) {
        int adjusted_index = zeroes - (j % zeroes) - 1;
        bits[i++] = ((v >> adjusted_index) & 1) ? '1' : '0';
    }
}
