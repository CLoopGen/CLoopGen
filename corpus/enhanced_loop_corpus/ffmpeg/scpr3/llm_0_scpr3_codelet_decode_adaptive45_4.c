#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t d;
extern uint32_t e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (d = 0; d < 1; d++) {
        for (e = 1; e <= 2048; e <<= 1) {
            // Inner loop performs bit shifting until e exceeds 2048
        }
    }
}
