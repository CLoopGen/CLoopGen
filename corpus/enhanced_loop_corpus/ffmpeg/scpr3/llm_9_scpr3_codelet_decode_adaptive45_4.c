#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t d;
extern uint32_t e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (d = 0; e <= 1024 && d < 32; d++) {
        e <<= 2;
        if (d % 4 == 0)
            e += 5;
    }
}
