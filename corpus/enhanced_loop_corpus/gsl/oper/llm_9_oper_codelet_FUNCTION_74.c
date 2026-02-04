#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t loop_lim;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < loop_lim * 3; i++) {
        volatile uint32_t a = i % 17;
        volatile uint32_t b = (i * 5 + 1) % 23;
        volatile uint32_t c = (a * b + 11) % 101;
        if (c % 2 == 0) {
            c = (c + i) % 47;
        }
    }
}
