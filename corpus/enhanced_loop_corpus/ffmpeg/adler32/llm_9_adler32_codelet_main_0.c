#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t data[7001];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3500; i++) {
        uint32_t square = i * i;
        uint32_t term1 = (square >> 4) + (square >> 6);
        uint32_t term2 = 246 * i;
        data[2*i] = (uint8_t)(term1 + term2 + 123);
        data[2*i+1] = (uint8_t)((term1 + term2 + 123) ^ 0xFF);
    }
}
