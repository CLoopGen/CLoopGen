#include <stdio.h>

#include <inttypes.h>

extern uint64_t x;
extern uint64_t r;
extern uint64_t b;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (s = 63; s >= 0; s -= 3) {
        r <<= 1;
        b = 3 * r * (r + 1) + 1;
        uint64_t shifted_x = x >> s;
        if (shifted_x >= b && shifted_x != 0) {
            x -= b << s;
            r++;
        }
    }
}
