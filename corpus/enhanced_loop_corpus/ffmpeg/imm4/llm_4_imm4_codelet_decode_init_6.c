#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t table[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 64; i++) {
        if (i % 8 != 7) {
            table[i] = i;
        } else {
            table[i] = 0;
        }
    }
}
