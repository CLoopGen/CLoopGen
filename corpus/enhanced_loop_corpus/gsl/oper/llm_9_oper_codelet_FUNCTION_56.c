#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t loop_lim;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < loop_lim * 3; i++) {
        if (i % 3 == 0) {
            volatile uint32_t x = (i + 1) * 2;
        } else if (i % 3 == 1) {
            volatile uint32_t y = (i + 2) / 2;
        } else {
            volatile uint32_t z = (i * i) % 100;
        }
    }
}
