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
    for (i = 63; i >= 0; i--) {
        uint64_t shifted_a = a << 1;
        int condition = (a >= ((uint64_t)1 << 63)) || (shifted_a >= b);
        if (condition) {
            r |= (uint64_t)1 << i;
            a = shifted_a - b;
        } else {
            a = shifted_a;
        }
    }
}
