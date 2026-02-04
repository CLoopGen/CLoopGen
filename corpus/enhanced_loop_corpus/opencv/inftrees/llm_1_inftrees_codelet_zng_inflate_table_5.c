#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern uint16_t count[16];
extern uint16_t offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (uint16_t i = 1; i < 15; i++)
        offs[i + 1] = offs[i] + count[i];
    // Single-depth loop with simplified control variable and no additional nesting
}
