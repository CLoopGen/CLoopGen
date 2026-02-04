#include <stdio.h>

#include <inttypes.h>

extern uint64_t x;
extern uint64_t r;
extern uint64_t b;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (s = 63; s >= 0; s -= 2) {
        r <<= 1;
        b = 2 * r * (r + 1) + 1;
        if ((x >> s) >= b) {
            x -= b << s;
            r++;
        }
        // Additional arithmetic to increase computational intensity
        b += (r >> 1) + (x & 1);
    }
}
