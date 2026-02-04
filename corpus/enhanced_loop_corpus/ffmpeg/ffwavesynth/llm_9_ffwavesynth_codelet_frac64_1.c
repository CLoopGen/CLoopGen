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
for (i = 0; i < 2; i++) {
    a <<= 32;
    r = (r << 32) | (a / b);
    a %= b;
    if (a > b) {
        a -= b;
        r ^= a;
    }
}
}
