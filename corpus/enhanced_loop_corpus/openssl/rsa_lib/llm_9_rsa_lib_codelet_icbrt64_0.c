#include <stdio.h>

#include <inttypes.h>

extern uint64_t x;
extern uint64_t r;
extern uint64_t b;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (s = 60; s >= 0; s -= 4) {
        r <<= 2;
        uint64_t temp1 = r * (r + 2);
        uint64_t temp2 = 3 * temp1 + 1;
        b = temp2;
        if ((x >> s) >= b) {
            x -= b << s;
            r++;
        }
        // Extra operation to simulate higher complexity per iteration
        x ^= (r << 2) | (s & 7);
    }
}
