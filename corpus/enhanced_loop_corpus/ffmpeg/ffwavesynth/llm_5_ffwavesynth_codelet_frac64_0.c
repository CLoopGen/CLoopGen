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
        uint64_t temp_r = r;
        uint64_t temp_a = a;
        uint64_t shifted = a << 1;
        uint64_t mask = (uint64_t)1 << i;

        if (!(a >= ((uint64_t)1 << 63)) && shifted < b) {
            a = shifted;
        } else {
            r = temp_r | mask;
            a = shifted - b;
        }
    }
}
