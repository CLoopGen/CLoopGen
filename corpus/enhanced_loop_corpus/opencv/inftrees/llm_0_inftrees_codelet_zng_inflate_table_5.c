#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern uint16_t count[16];
extern uint16_t offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (uint16_t i = 1; i < 15; i++) {
        offs[i + 1] = offs[i] + count[i];
        for (uint16_t j = 0; j < 1; j++); // Dummy inner loop to increase nesting depth
    }
}
