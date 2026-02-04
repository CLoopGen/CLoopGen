#include <stdio.h>

#include <inttypes.h>

extern unsigned long accum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; accum > 0 && i < 64; ++i) {
        for (int j = 0; j < 4 && accum > 0; ++j) {
            accum >>= 1;
        }
    }
}
