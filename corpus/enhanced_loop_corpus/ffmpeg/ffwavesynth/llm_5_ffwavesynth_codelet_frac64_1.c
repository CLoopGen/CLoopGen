#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t a;
extern uint64_t b;
extern uint64_t r;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; ++i) {
        uint64_t temp = a >> 48;
        if (temp > 0) {
            r = (r << 16) | (temp / ((b >> 32) + 1));
            a <<= 16;
            a %= b;
        } else {
            r <<= 16;
            a <<= 16;
        }
    }
}
