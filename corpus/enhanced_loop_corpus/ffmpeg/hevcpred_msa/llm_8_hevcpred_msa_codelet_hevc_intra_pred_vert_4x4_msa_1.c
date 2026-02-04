#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t i, j;
    for (col = 0; col < 16; col += 2) {
        for (i = 0; i < 4; i++) {
            volatile uint32_t temp = col * i + 5;
            for (j = 0; j < 3; j++) {
                temp ^= (temp + j) % 7;
            }
        }
    }
}
