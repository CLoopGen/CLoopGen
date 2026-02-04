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
        uint64_t temp_a_shift = a << 1;
        uint64_t mask = (uint64_t)1 << i;
        int condition = (a >= ((uint64_t)1 << 63)) || (temp_a_shift >= b);
        r |= (-((uint64_t)condition)) & mask;
        a = condition ? (temp_a_shift - b) : temp_a_shift;
    }
}
