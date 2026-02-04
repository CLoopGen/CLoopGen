#include <stdio.h>

#include <inttypes.h>

extern unsigned long accum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; accum > 0; ++i) {
        accum >>= 2;
        if (accum & 1) {
            accum += 3;
        }
    }
}
