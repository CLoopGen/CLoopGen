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
    for (i = 0; i < 4; i++) {
        for (int j = 0; j < 1; j++) { // Increased nesting depth by adding a redundant inner loop
            a <<= 16;
            r = (r << 16) | (a / b);
            a %= b;
        }
    }
}
