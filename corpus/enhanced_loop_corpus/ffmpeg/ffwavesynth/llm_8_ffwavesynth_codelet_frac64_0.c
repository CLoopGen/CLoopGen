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
    for (i = 63; i >= 0; i -= 2) {
        uint64_t shift_val1 = (uint64_t)1 << i;
        uint64_t shift_val2 = (i > 0) ? ((uint64_t)1 << (i - 1)) : 0;
        if (a >= (uint64_t)1 << 63 || a << 1 >= b) {
            r |= shift_val1;
            a = (a << 1) - b;
            if (i > 0 && (a >= (uint64_t)1 << 63 || a << 1 >= b)) {
                r |= shift_val2;
                a = (a << 1) - b;
            } else if (i > 0) {
                a <<= 1;
            }
        } else {
            a <<= 1;
            if (i > 0) {
                a <<= 1;
            }
        }
    }
}
