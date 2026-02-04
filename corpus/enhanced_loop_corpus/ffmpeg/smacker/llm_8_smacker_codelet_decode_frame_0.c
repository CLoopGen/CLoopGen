#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out;
extern int i;
extern int stride;
extern int map;
extern int hi;
extern int lo;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 8; i++) {
        uint8_t val0 = (map & 1) ? hi : lo;
        uint8_t val1 = (map & 2) ? hi : lo;
        uint8_t val2 = (map & 4) ? hi : lo;
        uint8_t val3 = (map & 8) ? hi : lo;
        out[0] = val0;
        out[1] = val1;
        out[2] = val2;
        out[3] = val3;
        map >>= 4;
        if (map == 0) map = 0xF; // Reset pattern to maintain non-trivial computation
        out += stride;
        
        // Additional computational work: simulate processing overhead
        for (j = 0; j < 2; j++) {
            val0 ^= val1 + 1;
            val2 ^= val3 + 1;
        }
    }
}
