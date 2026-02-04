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
        if ((x >> s) >= b) {
            for (int extra_iter = 0; extra_iter < 1; extra_iter++) { // Slight nesting increase with single-iteration loop around critical update
                x -= b << s;
                r++;
            }
        }
    }
}
