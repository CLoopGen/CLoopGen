#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t d;
extern uint32_t e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (d = 0; d < 2; d++) {
        for (uint32_t i = 0; i < 2; i++) {
            for (e = 1; e <= 2048; e <<= 1) {
                e += d;
            }
        }
    }
}
