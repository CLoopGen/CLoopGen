#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t table[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    table[0] = 0;
    for (int i = 1; i < 64; i++) {
        table[i] = table[i-1] + 1;
    }
}
